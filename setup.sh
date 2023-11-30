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
sudo dpkg -i google-chrome-stable_current_amd64.deb
#sudo cp -r /mnt/sd/config/* /home/kali/.config
google-chrome-stable &
#cd /mnt/sd/config/google-chrome
#sudo cp -r * /home/kali/.config/google-chrome
#numlockx on
cd /etc/apt
sudo chmod 666 sources.list
sudo cp sources.list sources.list.orig
sudo  echo "deb http://http.kali.org/kali kali-rolling main non-free contrib" > /etc/apt/sources.list
sudo apt update
sudo apt --fix-broken install
sudo apt install -y numlockx
numlockx on
sudo usermod -aG audio kali

