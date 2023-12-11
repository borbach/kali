chr=/home/bill/testroot
mkdir -p $chr
mkdir -p $chr/bin
mkdir -p $chr/lib
mkdir -p $chr/lib64
cd $chr
cp -v /bin/bash $chr/bin
cp -v /bin/touch $chr/bin
cp -v /bin/ls $chr/bin
cp -v /bin/rm $chr/bin
list="$(ldd /bin/bash | egrep -o '/lib.*\.[0-9]')"
echo $list
for i in $list; do cp -v --parents "$i" "${chr}"; done
list="$(ldd /bin/touch | egrep -o '/lib.*\.[0-9]')"
for i in $list; do cp -v --parents "$i" "${chr}"; done
list="$(ldd /bin/ls | egrep -o '/lib.*\.[0-9]')"
for i in $list; do cp -v --parents "$i" "${chr}"; done
list="$(ldd /bin/ls | egrep -o '/lib.*\.[0-9]')"
for i in $list; do cp -v --parents "$i" "${chr}"; done
sudo chroot $chr /bin/bash
