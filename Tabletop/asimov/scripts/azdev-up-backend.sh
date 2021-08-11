#!/bin/bash
sudo docker-compose -f asimov/azdev/docker-compose-azdev-lsdb.yml up $@ --build --remove-orphans
