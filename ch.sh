
cd /mnt
mkdir proc
mkdir sys
mkdir dev
mkdir sbin
mkdir bin
mkdir usr 
mkdir lib 
mkdir lib32 
mkdir lib64 
mkdir boot 
mkdir etc 
mkdir home 
mkdir media 
mkdir opt 
mkdir root 
mkdir srv 
mkdir sys
mount --bind /proc /mnt/proc
mount --bind /sys /mnt/sys
mount --bind /dev /mnt/dev
mount --bind /sbin /mnt/sbin
mount --bind /bin /mnt/bin
mount --bind /usr /mnt/usr
mount --bind /lib /mnt/lib
mount --bind /lib32 /mnt/lib32
mount --bind /lib64 /mnt/lib64
mount --bind /lib64 /mnt/lib64
mount --bind /boot /mnt/boot/
mount --bind /etc /mnt/etc
mount --bind /home /mnt/home
mount --bind /media /mnt/media
mount --bind /opt /mnt/opt
mount --bind /root /mnt/root
mount --bind /srv /mnt/srv
mount --bind /sys /mnt/sys
mount --bind /lib64 /mnt/lib64
mount --bind /lib64 /mnt/lib64

chroot /mnt /bin/zsh

