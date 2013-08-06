#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: squid.sh,v 1.22 2013/08/06 15:44:34 adam Exp $
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

# Note: 'shutdown' waits 30 seconds, while 'interrupt' stops immediately
stop_cmd="${command} ${squid_flags} ${command_args} -k interrupt"
reload_cmd="${command} ${squid_flags} ${command_args} -k reconfigure"
rotate_cmd="${command} ${squid_flags} ${command_args} -k rotate"
createdirs_cmd="${command} ${squid_flags} ${command_args} -z"
extra_commands="createdirs reload rotate"

if [ -f /etc/rc.subr -a -f /etc/rc.conf -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	if [ -f /etc/rc.conf ]; then
		. /etc/rc.conf
	fi
	case $1 in
	start)
		start_cmd="${command} ${squid_flags} ${command_args}"
		if [ -x ${command} -a -f ${squid_conf} ] ; then
			${start_cmd}
		fi
		;;
	stop)
		${stop_cmd}
		;;
	createdirs)
		${createdirs_cmd}
		;;
	reload)
		if [ -r "${pidfile}" ] ; then
			${reload_cmd}
		fi
		;;
	rotate)
		if [ -r "${pidfile}" ] ; then
			${rotate_cmd}
		fi
		;;
	*)
		@ECHO@ "Usage: $0 {start|stop|reload|rotate|createdirs}" 1>&2
		exit 64
		;;
	esac
fi
