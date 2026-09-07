$ErrorActionPreference = "Stop"

#compila el main con el nombre MV.exe y lo guarda en versions
& gcc -Wall -Wextra .\main.c -o .\versions\MV.exe

if ($LASTEXITCODE -ne 0) {
    exit $LASTEXITCODE
}

& .\versions\MV.exe
exit $LASTEXITCODE
