#!/usr/bin/bash

serviceName=file_chkd.service
fileServiceName="/etc/systemd/system/$serviceName"
sudo touch $fileServiceName
sudo chmod 777 $fileServiceName

execFileName="/usr/exec.sh"
sudo touch $execFileName
sudo chmod 777 $execFileName

{
    echo "#!/usr/bin/bash"
    echo "sudo \"/usr/checkf\""
} >$execFileName

{
    sudo echo "[Unit]"
    sudo echo "Description=Monitoring files in."
    sudo echo "After=network.service"

    sudo echo "[Service]"
    sudo echo "Type=simple"
    sudo echo "ExecStart=/usr/exec.sh"
    sudo echo "Restart=on-abnormal"

    sudo echo "[Install]"
    sudo echo "WantedBy=default.target"
} >$fileServiceName

sudo systemctl daemon-reload
sudo systemctl start $serviceName
