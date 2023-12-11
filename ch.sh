chr=/home/bill/testroot
mkdir -p $chr
mkdir -p $chr/bin
mkdir -p $chr/lib
mkdir -p $chr/lib64
cd $chr
cp -v /bin/bash $chr/bin
list="$(ldd /bin/bash | egrep -o '/lib.*\.[0-9]')"
echo $list
for i in $list; do cp -v --parents "$i" "${chr}"; done
cp -v /bin/touch $chr/bin
list="$(ldd /bin/touch | egrep -o '/lib.*\.[0-9]')"
echo $list
for i in $list; do cp -v --parents "$i" "${chr}"; done
cp -v /bin/ls $chr/bin
list="$(ldd /bin/ls | egrep -o '/lib.*\.[0-9]')"
echo $list
for i in $list; do cp -v --parents "$i" "${chr}"; done
cp -v /bin/rm $chr/bin
list="$(ldd /bin/rm | egrep -o '/lib.*\.[0-9]')"
echo $list
for i in $list; do cp -v --parents "$i" "${chr}"; done
cp -v /bin/find $chr/bin
list="$(ldd /bin/find | egrep -o '/lib.*\.[0-9]')"
echo $list
for i in $list; do cp -v --parents "$i" "${chr}"; done
cp -v /usr/sbin/grub-install $chr/bin
list="$(ldd /usr/sbin/grub-install | egrep -o '/lib.*\.[0-9]')"
echo $list
for i in $list; do cp -v --parents "$i" "${chr}"; done
cp -v /usr/sbin/update-grub $chr/bin
list="$(ldd /usr/sbin/update-grub | egrep -o '/lib.*\.[0-9]')"
echo $list
for i in $list; do cp -v --parents "$i" "${chr}"; done
cp -v /usr/sbin/grub-mkconfig $chr/bin
list="$(ldd /usr/sbin/grub-mkconfig | egrep -o '/lib.*\.[0-9]')"
echo $list
for i in $list; do cp -v --parents "$i" "${chr}"; done
sudo chroot $chr /bin/bash
