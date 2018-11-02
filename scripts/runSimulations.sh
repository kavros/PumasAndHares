#!/bin/bash -x

date
for i in {1..9}
do
	
#small landscape
./build/bin/pumasAndHares -c "./data/configs/config${i}.json" -i ./data/landscapes/10x10_1.dat -p "10x10_1_config${i}_"
./build/bin/pumasAndHares -c "./data/configs/config${i}.json" -i ./data/landscapes/10x10_3.dat -p "10x10_3_config${i}_"
./build/bin/pumasAndHares -c "./data/configs/config${i}.json" -i ./data/landscapes/10x10_7.dat -p "10x10_7_config${i}_"
./build/bin/pumasAndHares -c "./data/configs/config${i}.json" -i ./data/landscapes/10x10_9.dat -p "10x10_9_config${i}_"

#medium size landscape
./build/bin/pumasAndHares -c "./data/configs/config${i}.json" -i ./data/landscapes/100x100_1.dat -p "100x100_1_config${i}_"
./build/bin/pumasAndHares -c "./data/configs/config${i}.json" -i ./data/landscapes/100x100_3.dat -p "100x100_3_config${i}_"
./build/bin/pumasAndHares -c "./data/configs/config${i}.json" -i ./data/landscapes/100x100_7.dat -p "100x100_7_config${i}_"
./build/bin/pumasAndHares -c "./data/configs/config${i}.json" -i ./data/landscapes/100x100_9.dat -p "100x100_9_config${i}_"

#large size landscape
./build/bin/pumasAndHares -c "./data/configs/config${i}.json" -i ./data/landscapes/1000x1000_1.dat -p "1000x1000_1_config${i}_"
./build/bin/pumasAndHares -c "./data/configs/config${i}.json" -i ./data/landscapes/1000x1000_3.dat -p "1000x1000_3_config${i}_"
./build/bin/pumasAndHares -c "./data/configs/config${i}.json" -i ./data/landscapes/1000x1000_7.dat -p "1000x1000_7_config${i}_"
./build/bin/pumasAndHares -c "./data/configs/config${i}.json" -i ./data/landscapes/1000x1000_9.dat -p "1000x1000_9_config${i}_"

#maximum size landscape
./build/bin/pumasAndHares -c "./data/configs/config${i}.json" -i ./data/landscapes/2000x2000_1.dat -p "2000x2000_1_config${i}_" 
./build/bin/pumasAndHares -c "./data/configs/config${i}.json" -i ./data/landscapes/2000x2000_3.dat -p "2000x2000_3_config${i}_" 
./build/bin/pumasAndHares -c "./data/configs/config${i}.json" -i ./data/landscapes/2000x2000_7.dat -p "2000x2000_7_config${i}_" 
./build/bin/pumasAndHares -c "./data/configs/config${i}.json" -i ./data/landscapes/2000x2000_9.dat -p "2000x2000_9_config${i}_" 

done
date











