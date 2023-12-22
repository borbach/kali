mount $1 /mnt/sd
cd /mnt/sd
mkdir boot
mkdir bin
mkdir lib 
mkdir lib32
mkdir lib64
mkdir libx32
mkdir usr
mkdir proc 
mkdir dev
mkdir etc
mkdir var
mkdir media 
mkdir opt
mkdir root
mkdir run
mkdir sbin
mkdir srv
mkdir sys
mount -t proc none /mnt/sd/proc
mount --rbind /sys /mnt/sd/sys
mount --rbind /boot /mnt/sd/boot
mount --rbind /bin /mnt/sd/bin
mount --rbind /lib /mnt/sd/lib
mount --rbind /lib32 /mnt/sd/lib32
mount --rbind /lib64 /mnt/sd/lib64
mount --rbind /libx32 /mnt/sd/libx32
mount --rbind /usr /mnt/sd/usr
mount --rbind /dev /mnt/sd/dev
mount --rbind /etc /mnt/sd/etc
mount --rbind /var /mnt/sd/var
mount --rbind /media /mnt/sd/media
mount --rbind /opt /mnt/sd/opt
mount --rbind /root /mnt/sd/root
mount --rbind /run /mnt/sd/run
mount --rbind /sbin /mnt/sd/sbin
mount --rbind /srv /mnt/sd/srv
mount --rbind /sys /mnt/sd/sys
echo "we are chroot into " $1
chroot /mnt/sd

