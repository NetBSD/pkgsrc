#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: xfstt.sh,v 1.5 2003/02/22 13:33:31 salo Exp $
#
# PROVIDE: xfstt
# REQUIRE: DAEMON

. /etc/rc.subr

name="xfstt"
rcvar=$name
command="@PREFIX@/bin/${name}"
command_args="--user nobody --notcp --daemon"
pidfile="/var/run/${name}.pid"
start_precmd="${command} --sync >/dev/null"

load_rc_config $name
run_rc_command "$1"
