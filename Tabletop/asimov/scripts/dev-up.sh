#!/bin/bash
sudo docker-compose -f asimov/dev/docker-compose.yml up $@ --build --remove-orphans
