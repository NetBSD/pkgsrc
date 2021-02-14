#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: unit.sh,v 1.1 2021/02/14 11:56:57 otis Exp $
#
# PROVIDE: unit
# REQUIRE: DAEMON

. /etc/rc.subr

name="unit"
rcvar=${name}
command="@PREFIX@/sbin/${name}d"
pidfile="@VARBASE@/run/${name}.pid"
start_precmd="ulimit -n 2048"

load_rc_config $name
run_rc_command "$1"
