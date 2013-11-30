#!/usr/bin/env python

""" This version of videocap script is one-shot.
It only tries to upload the file once and exit.
"""

import cv
from time import *
import os  # "from os import *" causes name collision of "open"
from stat import *


try:
	tm = time()
	lt = localtime(tm)
	outdir = strftime("%Y-%m-%d", lt)
	outfilename = strftime("%Y-%m-%d-%H-%M.jpg", lt)
	print("Now: " + outfilename + " (%d sec)" % lt.tm_sec)
	outpath = outdir + "/" + outfilename

	if os.path.isfile(outpath):
		exit

	capture = cv.CaptureFromCAM(0)

	img = cv.QueryFrame(capture)

	print("Saving " + outpath + "\n")

	if not os.path.isdir(outdir):
		os.mkdir(outdir)

	cv.SaveImage(outpath, img)

	del capture

	os.system("ruby post.rb " + outpath)

#	raise Exception("test except")

except Exception as e:
	print(e.message)
	f = open('videocap.log', 'a')
	f.write(asctime() + ": ")
	f.write("type: " + str(type(e)) + ", ")
	f.write("args: " + str(e.args) + ", ")
	f.write("message: " + e.message)
	f.write("\n")
	f.close

