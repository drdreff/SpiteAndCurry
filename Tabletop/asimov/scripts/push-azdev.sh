if [ $# -eq 0 ]
  then
    echo "No arguments supplied"
else
    git pull
    sed -i s/ENV\ REACT_APP_LSDB_BUILD\ DEVELOPMENT/ENV\ REACT_APP_LSDB_BUILD\ v"$1"/g asimov/azdev/Dockerfile-lsdb-azure-dev
    sed -i s/ENV\ REACT_APP_LSDB_BUILD\ DEVELOPMENT/ENV\ REACT_APP_LSDB_BUILD\ v"$1"/g asimov/azdev/Dockerfile-node-azure-dev
    sudo docker-compose -f asimov/azdev/docker-compose-azure-dev.yml build
    sudo docker tag azdev_haveblue-node havebluecontainers.azurecr.io/azdev_haveblue-node:v"$1"
    sudo docker tag azdev_haveblue-django havebluecontainers.azurecr.io/azdev_haveblue-django:v"$1"
    az login
    az acr login --name havebluecontainers
    sudo docker push havebluecontainers.azurecr.io/azdev_haveblue-node:v"$1"
    sudo docker push havebluecontainers.azurecr.io/azdev_haveblue-django:v"$1"
    git checkout -- asimov/azdev/Dockerfile-lsdb-azure-dev asimov/azdev/Dockerfile-node-azure-dev
fi
