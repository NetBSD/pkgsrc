#!/bin/sh
#
# $NetBSD: apache.sh,v 1.12 2001/05/08 18:13:51 jlam Exp $
#
# PROVIDE: apache
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# To start apache at startup, copy this script to /etc/rc.d and set
# apache=YES in /etc/rc.conf.

name="apache"
rcvar=$name
command="@PREFIX@/sbin/apachectl"

if [ -f @APACHE_SYSCONFDIR@/apache_start.conf ]
then
	# This file can reset apache_start to "startssl"
	. @APACHE_SYSCONFDIR@/apache_start.conf
fi

apache_doit()
{
	action=$1

	case ${action} in
	start)		echo -n "Starting ${name}: "; action=${apache_start} ;;
	stop)		echo -n "Stopping ${name}: " ;;
	restart)	echo -n "Restarting ${name}: " ;;
	esac

	${command} ${command_args} ${action}
}

checkyesno()
{
	eval _value=\$${1}
	case $_value in
	[Yy][Ee][Ss]|[Tt][Rr][Uu][Ee]|[Oo][Nn]|1)	return 0 ;;
	[Nn][Oo]|[Ff][Aa][Ll][Ss][Ee]|[Oo][Ff][Ff]|0)	return 1 ;;
	*)
		echo "\$${1} is not set properly."
		return 1
		;;
	esac
}

if [ -r /etc/rc.conf ]
then
	. /etc/rc.conf
else
	eval ${rcvar}=YES
fi

if checkyesno ${rcvar}
then
	cmd=${1:-start}

	if [ -x ${command} ]
	then
		case ${cmd} in
		restart|start|stop|status)
			${rcvar}_doit ${cmd}
			;;
		*)
			echo 1>&2 "Usage: $0 [restart|start|stop|status]"
			exit 1
			;;
		esac
	fi
fi
