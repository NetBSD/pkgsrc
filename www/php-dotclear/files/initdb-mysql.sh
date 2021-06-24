#!/bin/sh
#
# Create role and database for the MySQL backend.
#
# sh @PREFIX@/share/examples/dotclear/initdb-mysql.sh

dcuser=dotclear
dcdbname=dotclear

read -p "Enter MySQL admin username [$(whoami)]: " admuser
if [ ! ${admuser} ] ; then admuser=$(whoami) ; fi
stty -echo
printf "Enter MySQL admin password: "
read admpasswd
stty echo
printf "\n"
read -p "Enter dotclear user name [${dcuser}]: " tmp
if [ ${tmp} ] ; then dcuser=${tmp} ; fi
stty -echo
printf "Enter dotclear user password: "
read dcpasswd
stty echo
printf "\n"
read -p "Enter dotclear database name [${dcdbname}]: " tmp
if [ ${tmp} ] ; then dcdbname=${tmp} ; fi

cat << EOF | @PREFIX@/bin/mysql --user=${admuser} --password=${admpasswd}
CREATE USER '${dcuser}'@'localhost' IDENTIFIED BY '${dcpasswd}';
CREATE DATABASE ${dcdbname};
GRANT ALL ON ${dcdbname}.* TO '${dcuser}'@'localhost';
EOF
