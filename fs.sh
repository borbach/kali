sudo fdisk --wipe=never -t dos /dev/sda
#then p
#then n and create partition 3 as primary
#then w
sudo mkfs.ext3 /dev/sda3
#sudo mkfs.exfat /dev/sda3
#then create a subdirectory off /mnt like sd3
#
#and mount /dev/sda3 /mnt/sd3
#
cd /mnt
sudo mkdir sd3
sudo mount /dev/sda3 /mnt/sd3
cd sd3
sudo mkdir home
sudo cp -r /home/kali /mnt/sd3/home
cd /home
sudo mv kali kali1
sudo ln -s /mnt/sd3/home/kali kali

dmesg
sudo fdisk -l
lsblk -f
blkid
lsmod | grep sd
fsck /dev/mmcblk0
sudo smartctl -a /dev/mmcblk0

