#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: privoxy.sh,v 1.7 2025/05/29 13:24:48 khorben Exp $
#
# Startup script for privoxy
#
# PROVIDE: privoxy
# REQUIRE: DAEMON
#
# You will need to set some variables in @SYSCONFBASE@/rc.conf to start privoxy:
#
# privoxy=YES

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr

name="privoxy"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/${name}.pid"
pconfig="@PKG_SYSCONFDIR@/config"
puser="@PRIVOXY_USER@"
required_files="$pconfig"
command_args="--pidfile ${pidfile} --user ${puser} ${pconfig} 2>/dev/null"

load_rc_config $name
run_rc_command "$1"
