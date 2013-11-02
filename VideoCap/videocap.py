import cv
from time import *
from os import *
from stat import *

capture = cv.CaptureFromCAM(0)

img = cv.QueryFrame(capture)

tm = time()
lt = localtime(tm)
outdir = strftime("%Y-%m-%d", lt)
outfilename = strftime("%Y-%m-%d-%H-%M.jpg", lt)

print("Saving " + outfilename + "\n")

if not path.isdir(outdir):
	mkdir(outdir)

cv.SaveImage(outdir + "/" + outfilename, img)


