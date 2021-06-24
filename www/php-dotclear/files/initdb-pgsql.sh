#!/bin/sh
#
# Create role and database for PostgreSQL backend.
#
# sh @PREFIX@/share/examples/dotclear/init-pgsql.sh

dbuser=dotclear
dbname=dotclear

@PREFIX@/bin/createuser --no-createdb --encrypted --no-superuser --pwprompt --username=pgsql ${dbuser}
@PREFIX@/bin/createdb --owner=${dbuser} --username=pgsql ${dbname}
