#!/bin/bash
echo "creating fixtures from dev_lsdb_1"
sudo docker exec -it dev_lsdb_1 lsdb/scripts/makefixtures.sh
