mount $1 /mnt/sd
cd /mnt/sd
mkdir dev
mkdir bin
mkdir lib
mkdir etc 
mkdir lib32 
mkdir lib64
mkdir libx32 
mkdir usr 
mkdir usr/lib 
mkdir usr/lib/x86_64-linux-gnu 
mkdir usr/lib/x86_64-linux-gnu/zsh
mkdir usr/lib/x86_64-linux-gnu/zsh/5.9
mkdir usr/lib/x86_64-linux-gnu/zsh/5.9/zsh
mkdir usr/bin
mkdir usr/bin/zsh
mkdir usr/bin/zsh5
mount --bind /dev /mnt/sd/dev
mount --bind /bin /mnt/sd/bin
mount --bind /lib /mnt/sd/lib
mount --bind /etc /mnt/sd/etc
mount --bind /lib32 /mnt/sd/lib32
mount --bind /lib64 /mnt/sd/lib64
mount --bind /libx32 /mnt/sd/libx32
mount --bind /usr/lib/x86_64-linux-gnu/zsh/5.9/zsh /mnt/sd/usr/lib/x86_64-linux-gnu/zsh/5.9/zsh
mount --bind /usr/bin/zsh /mnt/sd/usr/bin/zsh
mount --bind /usr/bin/zsh /mnt/sd/usr/bin/zsh5
chroot /mnt/sd

