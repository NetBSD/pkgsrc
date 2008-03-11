#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: squid.sh,v 1.21 2008/03/11 15:46:41 taca Exp $
#

# PROVIDE: squid
# REQUIRE: DAEMON
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

: ${squid_conf:=@PKG_SYSCONFDIR@/squid.conf}

name="squid"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/${name}.pid"
required_files="${squid_conf} @PKG_SYSCONFDIR@/mime.conf"
command_args="-Y -f ${squid_conf}"

stop_cmd="stop_nicely"
kill_command="${command} ${squid_flags} ${command_args} -k shutdown"
reload_cmd="${command} ${squid_flags} ${command_args} -k reconfigure"
rotate_cmd="${command} ${squid_flags} ${command_args} -k rotate"
createdirs_cmd="${command} ${squid_flags} ${command_args} -z"
extra_commands="createdirs reload rotate"

#### end of configuration section ####

# XXX Shouldn't the default stop_cmd be this patient too?
#
stop_nicely ()
{
	if [ -f ${pidfile} ] ; then
		DAEMON_PID=`sed 1q ${pidfile}`
		@ECHO@ -n "Stopping ${name}"
		${kill_command}
		if [ ${DAEMON_PID} -ne 0 ]; then
			@ECHO@ -n '['
			for WAIT in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
			do
				if kill -0 ${DAEMON_PID} >/dev/null 2>&1; then
					sleep 4
					@ECHO@ -n '.'
					test $WAIT -lt 15 || kill ${DAEMON_PID}
				else
					break
				fi
			done
			@ECHO@ '].'
			unset WAIT
		fi
		unset DAEMON_PID
	fi
}

if [ -f /etc/rc.subr -a -f /etc/rc.conf -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	run_rc_command "$1"
else				# old NetBSD, Solaris, Linux, etc...
	if [ -f /etc/rc.conf ]; then
		. /etc/rc.conf
	fi
	case $1 in
	start)
		start_cmd="${command} ${squid_flags} ${command_args}"
		if [ -x ${command} -a -f ${squid_conf} ] ; then
			eval ${start_cmd} && @ECHO@ -n " ${name}"
		fi
		;;
	stop)
		${stop_cmd}
		;;
	createdirs)
		${createdirs_cmd}
		;;
	reload)
		if [ -f ${pidfile} ] ; then
			${reload_cmd}
		fi
		;;
	rotate)
		if [ -f ${pidfile} ] ; then
			${rotate_cmd}
		fi
		;;
	*)
		@ECHO@ "Usage: $0 {start|stop|reload|createdirs}" 1>&2
		exit 64
		;;
	esac
fi
