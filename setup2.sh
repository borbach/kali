sudo cp /mnt/sd/Fios-xQSj2.nmconnection /etc/NetworkManager/system-connections
sudo systemctl start NetworkManager.service
sudo systemctl status NetworkManager.service
sudo systemctl start networking.service
sudo systemctl status networking.service
sudo nmcli con reload
sudo nmcli networking on
sudo nmcli device status
sudo lsblk
sudo lspci

