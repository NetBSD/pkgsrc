#! /bin/sh
#
# $NetBSD: squid.sh,v 1.9 2001/07/29 16:41:19 tron Exp $
#

# PROVIDE: squid
# REQUIRE: DAEMON
# KEYWORD: shutdown

SQUID_CONF_DIR="@PREFIX@/etc/squid"

conf_file="${SQUID_CONF_DIR}/squid.conf"

name="squid"
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="${conf_file} ${SQUID_CONF_DIR}/squid-mime.conf"

start_cmd="@PREFIX@/sbin/RunCache ${conf_file} &"
stop_cmd="stop_nicely"
kill_command="${command} -k shutdown"
reload_cmd="${command} -k reconfigure"

#### end of configuration section ####

# XXX Shouldn't the default stop_cmd be this patient too?
#
stop_nicely ()
{
	if [ -f ${pidfile} ] ; then
		DAEMON_PID=`sed 1q ${pidfile}`
		echo -n "Stopping ${name}"
		${kill_command}
		if [ ${DAEMON_PID} -ne 0 ]; then
			echo -n '['
			while kill -0 ${DAEMON_PID} >/dev/null 2>&1; do
				sleep 2
				echo -n '.'
			done
			echo ']  Stopped.'
		fi
	fi
}

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	. /etc/rc.subr
	. /etc/rc.conf

	start_precmd="checkyesno squid"
	stop_precmd=${start_precmd}
	reload_precmd=${start_precmd}
	extra_commands="reload"

	if type load_rc_config > /dev/null 2>&1 ; then
		load_rc_config $name
	fi
	run_rc_command "$1"

else				# old NetBSD, Solaris, Linux, etc...

	case $1 in
	start)
		if [ -x ${command} -a -f ${conf_file} ] ; then
			eval ${start_cmd} && echo -n " ${name}"
		fi
		;;
	stop)
		${stop_cmd}
		;;
	reload)
		if [ -f ${pidfile} ] ; then
			${reload_cmd}
		fi
		;;
	*)
		echo "Usage: $0 {start|stop|reload}" 1>&2
		exit 64
		;;
	esac

fi
