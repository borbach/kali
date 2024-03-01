#use gparted to create an extra partition in the unused space
#insert entry for /dev/sda4 into fstab
#UUID of /dev/sda4 (wwith blkid) /extra ext4 defaults 0 1
#findmnt -D to see if mounted correctly
#mount -fav to check if mounted
#cp -r /usr /extr/usr
#You must now shutdown -r now the system and take the SD card and put it in another computer which is running linux.
#The current SD card cannot be an actively running system when you execute the following steps
#ln -s /home/bill/extra/usr /home/bill/usr
#if mount gives you an error message saying it is an LVM2 disk and can't mount it you need to mount it as follows:
#mount /dev/mapper/asus16--vg-root /mnt
#lrwxrwxrwx   1 root root     9 Dec  4 19:03 lib32 -> usr/lib32                                                            
#lrwxrwxrwx   1 root root     9 Dec  4 19:03 lib64 -> usr/lib64                                                            
#lrwxrwxrwx   1 root root     7 Dec  4 19:03 bin -> usr/bin
#lrwxrwxrwx   1 root root     7 Dec  4 19:03 lib -> usr/lib
#lrwxrwxrwx   1 root root     8 Dec  4 19:03 sbin -> usr/sbin


