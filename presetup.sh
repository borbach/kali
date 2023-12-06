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
efibootmgr
#In windows bcdedit /enum FIRMWARE

sudo grub-mkconfig > /boot/grub/grub.cfg

efiboptmgr
#There are various options with the efibootmgr command

sudo apt install grub-efi
#This will modift the /boot/efi/EFI/BOOT/BOOTX64.EFI
#As weil as the /boot/efi/EFI/kali/grubx64.efi
#

