#!/usr/bin/bash

filesPath="/usr/checkf"
serviceName="file_chkd.service"
servicePath="/etc/systemd/system/$serviceName"
execName="checkf_exec.sh"
execPath="$filesPath/$execName"
libName="checkf"
libPath="$filesPath/$libName"


sudo touch $servicePath
sudo chmod 777 $servicePath

sudo touch "$execPath"
sudo chmod 777 "$execPath"


{
    echo "#!/usr/bin/bash"
    echo "sudo \"$libPath\""
} >"$execPath"

{
    sudo echo "[Unit]"
    sudo echo "Description=Monitoring files in."
    sudo echo "After=network.service"

    sudo echo "[Service]"
    sudo echo "Type=simple"
    sudo echo "ExecStart=$execPath"
    sudo echo "Restart=on-abnormal"

    sudo echo "[Install]"
    sudo echo "WantedBy=default.target"
} >$servicePath

sudo systemctl daemon-reload
sudo systemctl start $serviceName
