#! /bin/sh
#
# $NetBSD: apache.sh,v 1.4 2000/09/12 14:50:51 jlam Exp $
#
# PROVIDE: apache
# REQUIRE: DAEMON

name="apache"
command="@PREFIX@/sbin/apachectl"
pidfile="/var/run/httpd.pid"
conffile="@PREFIX@/etc/httpd/httpd.conf"

apache_start="start"

if [ -f @PREFIX@/etc/mod_ssl.conf ]
then
	# This file can reset apache_start to "startssl"
	. @PREFIX@/etc/httpd/mod_ssl.conf
fi

cmd=${1:-start}

case ${cmd} in
start)
	if [ -x ${command} -a -f ${conffile} ]; then
		echo "Starting ${name}."
		${command} ${apache_start}
	fi
	;;
*)
	if [ -x ${command} ]; then
		${command} ${cmd}
	fi
	;;
esac
exit 0
