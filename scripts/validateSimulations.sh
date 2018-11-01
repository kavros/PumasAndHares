#!/bin/bash 
for i in {1..9}
do
python  ./scripts/validation.py\
		"./data/outputs/10x10_1_config${i}__averages.txt" \
		./data/landscapes/10X10_1.dat\
		"./data/outputs/10x10_1_config${i}_0.ppm"

python  ./scripts/validation.py\
		"./data/outputs/10x10_3_config${i}__averages.txt" \
		./data/landscapes/10X10_3.dat\
		./data/outputs/10x10_3_config${i}_0.ppm

python  ./scripts/validation.py\
		"./data/outputs/10x10_7_config${i}__averages.txt" \
		./data/landscapes/10X10_7.dat\
		"./data/outputs/10x10_7_config${i}_0.ppm"


python  ./scripts/validation.py\
		"./data/outputs/10x10_9_config${i}__averages.txt" \
		./data/landscapes/10X10_9.dat\
		"./data/outputs/10x10_9_config${i}_0.ppm"

###########
python  ./scripts/validation.py\
		"./data/outputs/100x100_1_config${i}__averages.txt" \
		./data/landscapes/100X100_1.dat\
		"./data/outputs/100x100_1_config${i}_0.ppm"

python  ./scripts/validation.py\
		"./data/outputs/100x100_3_config${i}__averages.txt" \
		./data/landscapes/100X100_3.dat\
		"./data/outputs/100x100_3_config${i}_0.ppm"

python  ./scripts/validation.py\
		"./data/outputs/100x100_7_config${i}__averages.txt" \
		./data/landscapes/100X100_7.dat\
		"./data/outputs/100x100_7_config${i}_0.ppm"


python  ./scripts/validation.py\
		"./data/outputs/100x100_9_config${i}__averages.txt" \
		./data/landscapes/100X100_9.dat\
		"./data/outputs/100x100_9_config${i}_0.ppm"

##############
#
#python  ./scripts/validation.py\
#		"./data/outputs/1000x1000_1_config${i}__averages.txt" \
#		./data/landscapes/1000X1000_1.dat\
#		"./data/outputs/1000x1000_1_config${i}_0.ppm"
#
#python  ./scripts/validation.py\
#		"./data/outputs/1000x1000_3_config${i}__averages.txt" \
#		./data/landscapes/1000X1000_3.dat\
#		"./data/outputs/1000x1000_3_config${i}_0.ppm"
#
#python  ./scripts/validation.py\
#		"./data/outputs/1000x1000_7_config${i}__averages.txt" \
#		./data/landscapes/1000X1000_7.dat\
#		"./data/outputs/1000x1000_7_config${i}_0.ppm"
#
#
#python  ./scripts/validation.py\
#		"./data/outputs/1000x1000_9_config${i}__averages.txt" \
#		./data/landscapes/1000X1000_9.dat\
#		"./data/outputs/1000x1000_9_config${i}_0.ppm"
#
#################
#
#python  ./scripts/validation.py\
#		"./data/outputs/2000x2000_1_config${i}__averages.txt" \
#		./data/landscapes/2000X2000_1.dat\
#		"./data/outputs/2000x2000_1_config${i}_0.ppm"
#
#python  ./scripts/validation.py\
#		"./data/outputs/2000x2000_3_config${i}__averages.txt" \
#		./data/landscapes/2000X2000_3.dat\
#		"./data/outputs/2000x2000_3_config${i}_0.ppm"
#
#python  ./scripts/validation.py\
#		"./data/outputs/2000x2000_7_config${i}__averages.txt" \
#		./data/landscapes/2000X2000_7.dat\
#		"./data/outputs/2000x2000_7_config${i}_0.ppm"
#
#
#python  ./scripts/validation.py\
#		"./data/outputs/2000x2000_9_config${i}__averages.txt" \
#		./data/landscapes/2000X2000_9.dat\
#		"./data/outputs/2000x2000_9_config${i}_0.ppm"
#
done