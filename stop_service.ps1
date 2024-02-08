Start-Process -FilePath 'wsl' -ArgumentList "sudo systemctl kill file_chkd && sudo rm /etc/systemd/system/file_chkd.service"
