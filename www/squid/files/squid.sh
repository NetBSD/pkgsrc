#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: squid.sh,v 1.20 2008/01/31 20:01:13 adam Exp $
#

# PROVIDE: squid
# REQUIRE: DAEMON
# KEYWORD: shutdown

conf_file="@PKG_SYSCONFDIR@/squid.conf"

name="squid"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/${name}.pid"
required_files="${conf_file} @PKG_SYSCONFDIR@/mime.conf"
command_args="-Y -f $conf_file"

stop_cmd="stop_nicely"
kill_command="${command} -k shutdown"
reload_cmd="${command} -k reconfigure"
rotate_cmd="${command} -k rotate"
createdirs_cmd="squid_createdirs"

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

# create the squid cache directories
squid_createdirs()
{
	${command} -z
}

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	. /etc/rc.subr
	. /etc/rc.conf

	extra_commands="createdirs reload rotate"
	load_rc_config $name
	run_rc_command "$1"

else				# old NetBSD, Solaris, Linux, etc...

	case $1 in
	start)
		if [ -x ${command} -a -f ${conf_file} ] ; then
			eval ${start_cmd} && @ECHO@ -n " ${name}"
		fi
		;;
	stop)
		${stop_cmd}
		;;
	createdirs)
		squid_createdirs
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
