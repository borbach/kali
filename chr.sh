mount /dev/sda1 /mnt/sd
mkdir bin
mkdir lib
mkdir lib64
mkdir usr 
mount --bind /bin /mnt/sd/bin
mount --bind /lib /mnt/sd/lib
mount --bind /lib64 /mnt/sd/lib64
mount --bind /usr /mnt/sd/usr
chroot /mnt/sd

