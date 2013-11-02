import cv
from time import *
from os import *
from stat import *

lastsave = ""

while True:
	sleep(10)
	tm = time()
	lt = localtime(tm)
	outdir = strftime("%Y-%m-%d", lt)
	outfilename = strftime("%Y-%m-%d-%H-%M.jpg", lt)
	print("Now: " + outfilename + " (%d sec)" % lt.tm_sec)
	outpath = outdir + "/" + outfilename

	if lastsave == outpath or path.isfile(outpath):
		continue

	capture = cv.CaptureFromCAM(0)

	img = cv.QueryFrame(capture)

	print("Saving " + outpath + "\n")

	if not path.isdir(outdir):
		mkdir(outdir)

	cv.SaveImage(outpath, img)

	del capture

	system("ruby post.rb " + outpath)

	lastsave = outpath


