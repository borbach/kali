#first do cd mnt
#sudo mkdir sd
#cd sd
#lsblk to see what the sd card is
#sudo mount /dev/SD CARD DRIVE /mnt/sd
#
cd /mnt/sd
sudo systemctl start apache2.service
sudo cp /mnt/sd/etc/apache2/apache2.conf /etc/apache2
sudo cp /mnt/sd/usr/lib/cgi-bin/* /usr/lib/cgi-bin
sudo cp /mnt/sd/var/www/html/* /var/www/html
sudo ln -s /etc/apache2/mods-available/cgi.load /etc/apache2/mods-enabled/cgi.load
sudo systemctl restart apache2.service
ifconfig
sudo systemctl start ssh.service

