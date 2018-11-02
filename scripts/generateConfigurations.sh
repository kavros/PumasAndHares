 ./build/bin/configurationGeneratorMain ./data/configs/config1.json -r 0.08 -a 0.04 -b 0.02 -m 0.06 -k 0.2 -l 0.2 -n 100 -d 0.3
 
#high birth rate for hares
./build/bin/configurationGeneratorMain ./data/configs/config2.json -r 0.15 -a 0.04 -b 0.02 -m 0.06 -k 0.2 -l 0.2 -n 100 -d 0.3

#high predation rate which pumas eat hares
./build/bin/configurationGeneratorMain ./data/configs/config3.json -r 0.08 -a 0.4 -b 0.02 -m 0.06 -k 0.2 -l 0.2 -n 100 -d 0.3

#high birth rate of puma
 ./build/bin/configurationGeneratorMain ./data/configs/config4.json -r 0.08 -a 0.04 -b 0.2 -m 0.06 -k 0.2 -l 0.2 -n 100 -d 0.3

#high puma mortality rate
./build/bin/configurationGeneratorMain ./data/configs/config5.json -r 0.08 -a 0.04 -b 0.02 -m 0.6 -k 0.2 -l 0.2 -n 100 -d 0.3

#high diffusion rate for hares
./build/bin/configurationGeneratorMain ./data/configs/config6.json -r 0.08 -a 0.04 -b 0.02 -m 0.06 -k 0.9 -l 0.2 -n 100 -d 0.3
 
#high diffusion rate for puma
./build/bin/configurationGeneratorMain ./data/configs/config7.json -r 0.08 -a 0.04 -b 0.02 -m 0.06 -k 0.2 -l 0.9 -n 100 -d 0.3

#high number for the timesteps
./build/bin/configurationGeneratorMain ./data/configs/config8.json -r 0.08 -a 0.04 -b 0.02 -m 0.06 -k 0.2 -l 0.2 -n 100 -d 0.9

#low number between outputs(many outputs)
 ./build/bin/configurationGeneratorMain ./data/configs/config9.json -r 0.08 -a 0.04 -b 0.02 -m 0.06 -k 0.2 -l 0.2 -n 10 -d 0.3