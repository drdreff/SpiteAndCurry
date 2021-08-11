@echo off

setlocal

set dir=%~dp0
echo This is the %dir%
cd /d %dir%
cd ..
cd dev

dir


set image_tag=latest
set image_full_name="devartis/djangodocker:%image_tag%"

echo == Building image %image_full_name%
docker build . -t %image_full_name%

echo == Authenticating
docker login -u="%DOCKER_USERNAME%" --password-stdin;

echo == Pushing image %image_full_name%
docker push %image_full_name%
echo === Push finished!

endlocal