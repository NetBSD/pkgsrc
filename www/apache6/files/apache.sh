#! /bin/sh
#
# $NetBSD: apache.sh,v 1.4 2000/11/14 19:58:05 itojun Exp $
#
# PROVIDE: apache
# REQUIRE: DAEMON

name="apache"
command="@PREFIX@/sbin/apachectl"
pidfile="/var/run/httpd.pid"
conffile="@PREFIX@/etc/httpd/httpd.conf"

apache_start="start"

if [ -f @PREFIX@/etc/httpd/mod_ssl.conf ]
then
	# This file can reset apache_start to "startssl"
	. @PREFIX@/etc/httpd/mod_ssl.conf
fi

cmd=${1:-start}

case ${cmd} in
start)
	if [ -x ${command} -a -f ${conffile} ]; then
		echo "Starting ${name}."
		${command} ${apache_start} > /dev/null
	fi
	;;
stop)
	if [ -x ${command} -a -f ${pidfile} ]; then
		echo "Stopping ${name}."
		${command} stop > /dev/null
	fi
	;;
restart)
	( $0 stop )
	sleep 5
	$0 start
	;;
*)
	if [ -x ${command} ]; then
		${command} ${cmd}
	fi
	;;
esac
exit 0
