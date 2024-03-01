#use gparted to create an extra partition in the unused space
#insert entry for /dev/sda4 into fstab
#UUID of /dev/sda4 (wwith blkid) /extra ext4 defaults 0 1
#findmnt -D to see if mounted correctly
#mount -fav to check if mounted
#
#
