#!/bin/sh

if [ "$DATABASE" = "postgres" ]
then
    echo "Waiting for postgres..."

    while ! nc -z $DBHOST $DBPORT; do
      sleep 0.1
    done

    echo "PostgreSQL started"
fi
python manage.py flush --no-input
python manage.py migrate
python manage.py loaddata lsdb/fixtures/init.json
python manage.py loaddata lsdb/fixtures/auth.json
python manage.py loaddata lsdb/fixtures/post-auth-init.json
python manage.py loaddata lsdb/fixtures/definitions.json
python manage.py loaddata lsdb/fixtures/azurefiles.json
python manage.py loaddata lsdb/fixtures/notes.json
python manage.py loaddata lsdb/fixtures/test_units.json
# python manage.py loaddata lsdb/fixtures/test.json

exec "$@"
