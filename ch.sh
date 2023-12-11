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
cp -v /bin/grep $chr/bin
list="$(ldd /bin/grep | egrep -o '/lib.*\.[0-9]')"
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
cp -v /bin/df $chr/bin
list="$(ldd /bin/df | egrep -o '/lib.*\.[0-9]')"
echo $list
for i in $list; do cp -v --parents "$i" "${chr}"; done
cp -v /bin/lsblk $chr/bin
list="$(ldd /bin/lsblk | egrep -o '/lib.*\.[0-9]')"
echo $list
for i in $list; do cp -v --parents "$i" "${chr}"; done
cp -r -v /boot $chr
mkdir $chr/usr
mkdir $chr/usr/lib
mkdir $chr/usr/share
cp -r -v /usr/lib/grub $chr/usr/lib/grub/
cp -r -v /usr/share/grub $chr/usr/share/grub/
#mkdir $chr/etc
cp -r -v /dev/ $chr/dev/
cp -r -v /etc/ $chr/etc/

mkdir $chr/sys
mkdir $chr/sys/firmware
cp -r -v /sys/firmware/efi $chr/sys/firmware/efi/

sudo chroot $chr /bin/bash
