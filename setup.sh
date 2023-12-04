#If you get into ddeveloper mode you can gt the crosh shell by pressing 
#CTRL-ALT-T for the crsh shell and then type shell
#Alternatively for the VT-2 shell you can press
#CTRL_ALT and refresh. To get back to chrome, you can press
#CTRL_ALT =left arrow on the top keyboard (F1 Key).
#You will need to download the file firmware-util.sh from mrchromebox.tech
#as follows:
#cd; curl -LOk mrchromebox.tech/firmware-util.sh && sudo bash firmware-util.sh
#and then follow the instructions to flash the firmware.
#On the Asus!$ when booting it up, press CTRL-L and then any nnumber.
#Then pick the USAB drive from the menu
#
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
sudo apt install -y  alsa-utils
numlockx on
sudo usermod -aG audio kali

