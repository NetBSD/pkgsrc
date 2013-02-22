#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nginx.sh,v 1.1 2013/02/22 17:06:54 imil Exp $
#
# PROVIDE: nginx
# REQUIRE: DAEMON

. /etc/rc.subr

name="nginx"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/${name}.conf"
pidfile="@VARBASE@/run/${name}.pid"
start_precmd="ulimit -n 2048"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
