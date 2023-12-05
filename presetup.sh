cd /mnt
lsblk
sudo mount /dev/mmcblk0p1 /mnt/sd
sudo mount /dev/mmcblk1p1 /mnt/sd
lsmod
lspci
lscpu
lsof
lspci -k | grep -A 3 Audio
aplay -L
pulseaudio
pavucontrol



