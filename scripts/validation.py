#!/usr/bin/env python3
import sys
#print "This is the name of the script: ", sys.argv[0]
#print "Number of arguments: ", len(sys.argv)
#print "The arguments are: " , str(sys.argv)
cmdLineArgs = str(sys.argv)

def main():
	
	if ( len(sys.argv) != 4 ):
		print "\n Please run script using the following format: python ./scripts/validation.py averages.txt landscape.txt image \n"
		return

	#get files names
	averagesFile = str(sys.argv[1])
	landscapeFile = str(sys.argv[2])
	imageFile = str(sys.argv[3])



	#get files content
	averageFileContent = open(averagesFile,"r").readlines()
	landscapeFileLines = open(landscapeFile,"r").readlines()
	imageFileLines = open(imageFile,"r").readlines()


	#parse data for first validation
	totalRowsInImage =  int(imageFileLines[2].split(" ")[0].strip())
	totalColumnsInImage = int(imageFileLines[2].split(" ")[1].strip())	
	totalRowsInLandscape = int(landscapeFileLines[0].split(" ")[0].strip())
	totalColumnsInLandscape = int(landscapeFileLines[0].split(" ")[1].strip())
	
	#first validation
	assert(totalColumnsInImage ==totalColumnsInLandscape )
	assert(totalRowsInImage ==totalRowsInLandscape )
	
	#parse data for second validation
	totalRedPixels=0
	totalGreenPixels=0
	totalBluePixels =0
	totalGreenPixels=0
	totalBlackPixels=0

	redPixelFormat = "198 43 0"
	bluePixelFormat = "0 41 158"
	greenPixelFormat = "0 150 0"
	blackPixelFormat = "0 0 0"

	currLineNumber =0
	for line in imageFileLines:
		if currLineNumber  <= 3 :
			currLineNumber=currLineNumber+1
			continue

		rowPixels = line.split("   ")
		for pixel in rowPixels:
			pixel =pixel.strip()
			if (pixel == redPixelFormat):
				totalRedPixels = totalRedPixels +1
			elif (pixel == greenPixelFormat):
				totalGreenPixels= totalGreenPixels +1
			elif (pixel == bluePixelFormat):
				totalBluePixels = totalBluePixels+1
			elif (pixel == blackPixelFormat):
				totalBlackPixels = totalBlackPixels+1
	
	#print "totalRedPixels:",totalRedPixels
	#print "totalBluePixels:",totalBluePixels
	#print "totalBlackPixels:",totalBlackPixels
	#print "totalGreenPixels",totalGreenPixels

	#second validation
	for line in averageFileContent:
		if ":" in line:
			avgValue=float(line.split(":")[1].strip());
			assert(avgValue > 0)

	#parse data from landscape input file
	totalWaterSquares=0
	totalLandSquares=0

	currLineNumber=0
	for line in landscapeFileLines:
		if currLineNumber ==0:
			currLineNumber=currLineNumber+1
			continue
		squares = line.split(" ")
		for square in squares:
			if(square == '1'):
				totalLandSquares = totalLandSquares +1
			elif(square == '0'):
				totalWaterSquares = totalWaterSquares+1
	

	#third validation
	assert(totalWaterSquares == totalBluePixels)
	assert(totalLandSquares == (totalGreenPixels+totalRedPixels+totalBlackPixels))

	totalPixels =  totalGreenPixels+totalBlackPixels+totalBluePixels+totalRedPixels
	assert(totalPixels == totalWaterSquares+totalLandSquares)



if __name__ == "__main__":
	main()
