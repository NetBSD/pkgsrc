#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: xfstt.sh,v 1.4 2002/09/29 12:58:37 wiz Exp $
#
# PROVIDE: xfstt
# REQUIRE: DAEMON

. /etc/rc.subr

name="xfstt"
command="@PREFIX@/bin/${name}"
command_args="--user nobody --notcp --daemon"
pidfile="/var/run/${name}.pid"
start_precmd="${command} --sync >/dev/null"

load_rc_config $name
run_rc_command "$1"
