#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: tinyproxy.sh,v 1.3 2017/02/18 05:59:23 nonaka Exp $
#

# PROVIDE: tinyproxy
# REQUIRE: DAEMON

. /etc/rc.subr

name="tinyproxy"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/tinyproxy/${name}.pid"
required_files="@PKG_SYSCONFDIR@/${name}.conf"

load_rc_config $name
run_rc_command "$1"
