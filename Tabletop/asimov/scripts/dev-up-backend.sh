#!/bin/bash
sudo docker-compose -f asimov/dev/docker-compose-backend.yml up $@ --build --remove-orphans
