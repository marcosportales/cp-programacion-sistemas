#!/usr/bin/bash

serviceName=file_chkd.service
fileName="/etc/systemd/system/$serviceName"
sudo touch $fileName
sudo chmod 777 $fileName

{
sudo echo "[Unit]"
sudo echo "Description=pos eso"
sudo echo "After=network.start"

sudo echo "[Service]"
sudo echo "ExcStart=/usr/checkf"
sudo echo "Type=simple"
sudo echo "Restart=on-failure"

sudo echo "[Install]"
sudo echo "WantedGy=default.target"
} > $fileName


sudo systemctl daemon-reload1
sudo systemctl start $serviceName
