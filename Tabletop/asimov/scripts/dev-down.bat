@echo off

setlocal

set dir=%~dp0
echo This is the %dir%
cd /d %dir%
cd ..
cd dev

dir

docker-compose down

endlocal

