$serviceName = "file_chkd.service"
$servicePath = "\\wsl$\Ubuntu\etc\systemd\system\$serviceName"
$execName = "checkf_exec.ps1"
$execPath = "\\wsl$\Ubuntu\usr\bin\$execName"
$libName = "checkf"
$libPath = "\\wsl$\Ubuntu\usr\bin\$libName"

# Crear el servicio y el ejecutable en la ubicación de WSL
New-Item -Path $servicePath -ItemType file
Set-Content -Path $servicePath -Value @"
[Unit]
Description=Monitoring files in.
After=network.service

[Service]
Type=simple
ExecStart='$execPath'
Restart=on-abnormal

[Install]
WantedBy=default.target
"@

New-Item -Path $execPath -ItemType file
Set-Content -Path $execPath -Value @"
& $libPath
"@

# Ejecutar systemctl daemon-reload y start en WSL
Start-Process -FilePath 'wsl' -ArgumentList 'sudo systemctl daemon-reload'
Start-Process -FilePath 'wsl' -ArgumentList "sudo systemctl start $serviceName"
