cd /
sudo find . -type f -mmin -1 | grep -v -e 'proc' -e 'sys' -e 'cache' -e 'run' > t
sudo find . -type f -cmin -1 | grep -v -e 'proc' -e 'sys' -e 'cache' -e 'run' > tt
sudo find . -type f -amin -1 | grep -v -e 'proc' -e 'sys' -e 'cache' -e 'run' > ttt
ls -lta t
ls -lta tt
ls -lta ttt

