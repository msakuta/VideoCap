require 'rubygems'
require 'httpclient'

# default values
Settings = {
	"uploader" => "/html/fujilog/upload.php"
}

# Parse the settings file in the local machine.
# Assumed file format is the same as the server settings.txt,
# i.e. each line contains an entry and a value separated by space.
f = open("settings.txt")
f.each {|i|
	entry = i.split(/\s+/)
	if 2 <= entry.size
		Settings[entry[0]] = entry[1]
	end
}
f.close

host = Settings["host"]
Urlbase = "http://" + host + "/"
QueueFile = "queue.txt"

Boundary = "123456789"
c = HTTPClient.new

# parse the settings file in the server.
# temporarily disabled because it tend to fail so often
#c.get_content(Urlbase + "html/fujilog/settings.txt").split("\n").each {|i|
#	entry = i.split(/\s+/)
#	if 2 <= entry.size
#		Settings[entry[0]] = entry[1]
#	end
#}

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
		print "Posting: " + Urlbase + Settings["uploader"] + "\n"
		postdata = { "fl" => fl, "dir" => dir }
		begin
			resultString = c.post_content(Urlbase + Settings["uploader"], postdata,
				"content-type" => "multipart/form-data, boundary=#{Boundary}")
			print "Server response: '" + resultString + "'\n"
			succeeded = resultString.split("\n")[0] == "succeeded"
		rescue
			print "Exception occurred in POST\n"
			succeeded = false
		end

		if not succeeded
			if queue_fail
				open(QueueFile, mode_enc="a") do |fp|
					fp.write(file + "\n")
					print "Written failed file " + file + " to " + QueueFile + "\n"
				end
			end
		else
			File.delete(file)
			ret = true
		end
	end

	return ret
end

if upload(c, ARGV[0], true)

	if File.exists?(QueueFile)
		print "Re-trying upload failed files...\n"
		open(QueueFile) do |qf|
			que = qf.read()
			que.split("\n").each do |i|
				upload(c, i, false)
			end
		end

		File.delete(QueueFile)
	end

#	Dir['**/*'].each {|f|
#		if File.directory?(f)
#		end
#	}
end

