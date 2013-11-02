require 'rubygems'
require 'httpclient'

host = `cat upload`
Urlbase = "http://" + host + "/"
QueueFile = "queue.txt"

Boundary = "123456"
c = HTTPClient.new

# default values
Settings = {
	"uploader" => "/html/fujilog/upload.php"
}

# parse the settings file in the server.
c.get_content(Urlbase + "html/fujilog/settings.txt").split("\n").each {|i|
	entry = i.split(/\s+/)
	if 2 <= entry.size
		Settings[entry[0]] = entry[1]
	end
}

# print Settings
#Settings.each{|key,value|
#	puts "Settings[" + key + "] = " + value
#}

def upload(c, file, queue_fail)
	ret = false
	dir = file[0..9]

	print "File: ", file, "\n"
	print "Dir: ", dir, "\n"

	# upload and print result
	open(file) do |fl|
		postdata = { "fl" => fl, "dir" => dir }
		resultString = c.post_content(Urlbase + Settings["uploader"], postdata,
			"content-type" => "multipart/form-data, boundary=#{Boundary}")
		puts resultString
		if resultString.split("\n")[0] != "succeeded"
			if queue_fail
				open(QueueFile, mode_enc="a") do |fp|
					fp.write(file + "\n")
					print "Written failed file " + file + " to " + QueueFile + "\n"
				end
			end
		else
			ret = true
		end
	end

	return ret
end

if upload(c, ARGV[0], true)

	if File.exists?(QueueFile)
		open(QueueFile) do |qf|
			que = qf.read()
			que.split("\n").each do |i|
				upload(c, i, false)
			end
		end

		File.delete(QueueFile)
	end
end