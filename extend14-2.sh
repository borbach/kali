fdisk -l
sleep 10
fdisk /dev/mmcblk0
sleep 10
fdisk -l
sleep 10
pvdisplay
sleep 10
pvcreate /dev/mmcblk0p3
sleep 10
pvdisplay
sleep 10
vgdisplay | grep Name
sleep 10
vgextend asus14-vg /dev/mmcblk0p3
sleep 10
vgdisplay
sleep 10
lvdisplay | grep Path
sleep 10
lvextend -l +100%FREE /dev/asus14-vg/root
sleep 10
lvdisplay
sleep 10
resize2fs /dev/asus14-vg/root
sleep 10
df -lh
sleep 10


