#!/bin/sh
#
# $NetBSD: apache.sh,v 1.14 2001/11/26 07:34:06 jlam Exp $
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

apache_start=start
if [ -f @PKG_SYSCONFDIR@/apache_start.conf ]
then
	# This file can reset apache_start to "startssl"
	. @PKG_SYSCONFDIR@/apache_start.conf
fi

# set defaults
if [ -r /etc/rc.conf ]
then
	. /etc/rc.conf
else
	eval ${rcvar}=YES
fi

# $flags from environment overrides ${rcvar}_flags
if [ -n "${flags}" ]
then
	eval ${rcvar}_flags="${flags}"
fi

apache_doit()
{
	action=$1

	case ${action} in
	start)		echo -n "Starting ${name}: "; action=${apache_start} ;;
	stop)		echo -n "Stopping ${name}: " ;;
	restart)	echo -n "Restarting ${name}: " ;;
	esac

	${command} ${apache_flags} ${command_args} ${action}
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

cmd=${1:-start}
case ${cmd} in
force*)
	cmd=${cmd#force}
	eval ${rcvar}=YES
	;;
esac

if checkyesno ${rcvar}
then
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
