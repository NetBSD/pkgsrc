#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: xfstt.sh,v 1.3 2002/09/27 14:47:06 grant Exp $
#
# PROVIDE: xfstt
# REQUIRE: DAEMON

. /etc/rc.subr

name="xfstt"
command="@PREFIX@/bin/${name}"
command_flags="--user nobody --notcp --daemon &"
pidfile="/var/run/${name}.pid"
start_precmd="${command} --sync >/dev/null"

load_rc_config $name
run_rc_command "$1"
