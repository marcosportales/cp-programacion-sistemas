$libName = "checkf"
$libPath = ".\$libName"
$pathSecInfo ="C:\sec-info"
$pathFileConf = "$pathSecInfo\file.conf"
$pathLog = "$pathSecInfo\log.txt"

if (-not (Test-Path $pathSecInfo)) {
    New-Item -ItemType Directory -Path $pathSecInfo
}

if(-not (Test-Path $pathFileConf)){
    New-Item -Path $pathFileConf -ItemType file
}

if(-not (Test-Path $pathLog)){
    New-Item -Path $pathLog -ItemType file
}

gcc -c main.c -o "$pathSecInfo\main.o"
ar -rv "$pathSecInfo\libcheckfile.a" "$pathSecInfo\main.o"
gcc -static -o $pathSecInfo\$libPath main.c -I. -L"$pathSecInfo" -lcheckfile
