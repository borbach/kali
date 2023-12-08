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
#To change the boot order sudo efibootmgr -o 0002 to put entry 2 first
#sudo efibootmgr -b 0001 -B to delete entry 0001
#You must also then use sudo update-grub to update grub
#
#
#To generate grub:
#gdisk /dev/sda
#mkfs.exfat /dev/sda
#gpartd to make firrst partition bootable
#grub-install /dev/sda
#update-grub
#
#
# cat /etc/fstab to see wher you booted from
# fdisk -l to see list of disks
# files for grub are in the following directories
# /boot
# #System.map-6.3.0-kali1-amd64  initrd.img-6.3.0-kali1-amd64
#config-6.3.0-kali1-amd64      lost+found
#efi                           vmlinuz-6.3.0-kali1-amd64
#grub
# and in /boot/efi/EFI/BOOT
# ther is a file called BOOTX64.EFI
# and i /boot/efi/EFI/kali
# there is a file called grubx64.efi
#and in /boot/grub there are the followng files:
#fonts  grub.cfg  grubenv  locale  themes  unicode.pf2  x86_64-efi
# grub.cfg looks as follows:
#  os $menuentry_id_option 'gnulinux-simple-6b8653b2-603b-43d2-9add-6cd6587c343
 os $menuentry_id_option 'gnulinux-simple-6b8653b2-603b-43d2-9add-6cd6587c343
e' {
        load_video
        insmod gzio
        if [ x$grub_platform = xxen ]; then insmod xzio; insmod lzopio; fi
        insmod part_gpt
        insmod ext2
        search --no-floppy --fs-uuid --set=root 535d47fb-00ce-4b6f-a694-6bfcd
cf5b520
        echo    'Loading Linux 6.3.0-kali1-amd64 ...'
        linux   /vmlinuz-6.3.0-kali1-amd64 root=/dev/mapper/asus16--vg-root r
o  quiet splash
        echo    'Loading initial ramdisk ...'
        initrd  /initrd.img-6.3.0-kali1-amd64
}
#Also in /etc/grub.d you have the followng files:
#00_header        10_linux      30_os-prober      40_custom  README
#05_debian_theme  20_linux_xen  30_uefi-firmware  41_custom
#
#And in /etc/default/grub.d you have:
#init-select.cfg  kali-themes.cfg

#You also have grub in /etc/default/
## If you change this file, run 'update-grub' afterwards to update
# /boot/grub/grub.cfg.
# For full documentation of the options in this file, see:
#   info -f grub -n 'Simple configuration'

GRUB_DEFAULT=0
GRUB_TIMEOUT=5
GRUB_DISTRIBUTOR=`lsb_release -i -s 2> /dev/null || echo Debian`
GRUB_CMDLINE_LINUX_DEFAULT="quiet"
GRUB_CMDLINE_LINUX=""

# If your computer has multiple operating systems installed, then you
# probably want to run os-prober. However, if your computer is a host
# for guest OSes installed via LVM or raw disk devices, running
# os-prober can cause damage to those guest OSes as it mounts
# filesystems to look for things.
GRUB_DISABLE_OS_PROBER=false

# Uncomment to enable BadRAM filtering, modify to suit your needs
# This works with Linux (no patch required) and with any kernel that obtains
# the memory map information from GRUB (GNU Mach, kernel of FreeBSD ...)
#GRUB_BADRAM="0x01234567,0xfefefefe,0x89abcdef,0xefefefef"

# Uncomment to disable graphical terminal
#GRUB_TERMINAL=console

# The resolution used on graphical terminal
# note that you can use only modes which your graphic card supports via VBE
# you can see them in real GRUB with the command `vbeinfo'
#GRUB_GFXMODE=640x480

# Uncomment if you don't want GRUB to pass "root=UUID=xxx" parameter to Linux
#GRUB_DISABLE_LINUX_UUID=true

# Uncomment to disable generation of recovery mode menu entries
#GRUB_DISABLE_RECOVERY="true"

# Uncomment to get a beep at grub start
#GRUB_INIT_TUNE="480 440 1"
#
#In /usr/lib/grub/ yyou have:grub-mkconfig_lib  x86_64-efi
# The lib file is actually a soft innk to /usr/share/grub
#In /usr/share/grub you have as fllows:
#scii.h    default   grub-mkconfig_lib  unicode.pf2
#ascii.pf2  euro.pf2  themes             widthspec.h
                                            
#The /boot directory looks like this:
#System.map-6.3.0-kali1-amd64  initrd.img-6.3.0-kali1-amd64
config-6.3.0-kali1-amd64      lost+found
efi                           vmlinuz-6.3.0-kali1-amd64
grub

#You caan run ldd to get file dependencies for an executable script
#For example ldd /usr/bin/zsh
#




