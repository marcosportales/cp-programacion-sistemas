#!/usr/bin/bash

serviceName=file_chkd.service
fileName="/etc/systemd/system/$serviceName"
sudo touch $fileName
sudo chmod 777 $fileName

{
sudo echo "[Unit]"
sudo echo "Description=Monitoring files in."
sudo echo "After=network.start"

sudo echo "[Service]"
sudo echo "ExecStart=/usr/checkf"
sudo echo "Type=simple"
sudo echo "Restart=on-failure"

sudo echo "[Install]"
sudo echo "WantedBy=default.target"
} > $fileName


sudo systemctl daemon-reload
sudo systemctl start $serviceName
