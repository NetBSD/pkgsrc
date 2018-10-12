#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: tinyproxy.sh,v 1.4 2018/10/12 13:57:46 adam Exp $
#

# PROVIDE: tinyproxy
# REQUIRE: DAEMON

. /etc/rc.subr

name="tinyproxy"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="@VARBASE@/run/tinyproxy/${name}.pid"
required_files="@PKG_SYSCONFDIR@/${name}.conf"

load_rc_config $name
run_rc_command "$1"
