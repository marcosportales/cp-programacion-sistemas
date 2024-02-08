serviceName="file_chkd.service"
servicePath="/etc/systemd/system/$serviceName"

sudo touch $servicePath
sudo chmod 777 $servicePath

{
    sudo echo "[Unit]"
    sudo echo "Description=Monitoring files in."
    sudo echo "After=network.service"

    sudo echo "[Service]"
    sudo echo "Type=simple"
    sudo echo "ExecStart=/mnt/c/sec-info/checkf.exe"
    sudo echo "Restart=on-abnormal"

    sudo echo "[Install]"
    sudo echo "WantedBy=default.target"
} >$servicePath

sudo systemctl daemon-reload
sudo systemctl start $serviceName