mkdir programs
cp *.tar programs
cd programs
mkdir etc
mkdir etc/apache2
mkdir usr 
mkdir usr/lib 
mkdir usr/lib/cgi-bin 
mkdir var
mkdir var/www
mkdir var/www/html
sudo systemctl start apache2.service
tar -xvf all-etc-apache2.tar -C etc/apache2
tar -xvf all-usr-lib-cgi-bin.tar -C usr/lib/cgi-bin
tar -xvf all-var-www-html.tar -C var/www/html
sudo cp /home/bill/programs/etc/apache2/apache2.conf /etc/apache2
sudo cp /home/bill/programs/usr/lib/cgi-bin/* /usr/lib/cgi-bin
sudo cp /home/bill/programs/var/www/html/* /var/www/html
sudo ln -s /etc/apache2/mods-available/cgi.load /etc/apache2/mods-enabled/cgi.load
cd /var/www/html
cp index.html.gen index.html
sudo systemctl restart apache2.service
#ifconfig
sudo systemctl start ssh.service
#sudo chmod 666 sources.list
#sudo cp sources.list sources.list.orig
#sudo  echo "deb http://http.kali.org/kali kali-rolling main non-free contrib" > /etc/apt/sources.list
#sudo apt update
#sudo apt --fix-broken install
