#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: wwwoffled.sh,v 1.2 2003/12/23 16:43:57 fredb Exp $
#
# PROVIDE: wwwoffled
# REQUIRE: DAEMON network
#

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="wwwoffled"
rcvar="${name}"
command="@PREFIX@/sbin/${name}"
control_prog="@PREFIX@/bin/wwwoffle"
command_args="-c @PKG_SYSCONFDIR@/wwwoffle.conf"
required_files="@PKG_SYSCONFDIR@/wwwoffle.conf"
start_cmd=wwwoffled_start
stop_cmd="${control_prog} ${command_args} -kill"
autodial_cmd="${control_prog} -autodial ${command_args}"
offline_cmd="${control_prog} -offline ${command_args}"
online_cmd="${control_prog} -online ${command_args}"
extra_commands="autodial offline online"

wwwoffled_start() {
	eval "${command} ${command_args}"
	eval "${control_prog} -online ${command_args}"
	eval "${control_prog} -fetch ${command_args}"
}

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	printf " ${name}"
	${start_cmd}
fi
