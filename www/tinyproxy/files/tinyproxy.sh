#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: tinyproxy.sh,v 1.2 2011/02/03 19:27:55 shattered Exp $
#

# PROVIDE: tinyproxy
# REQUIRE: DAEMON

. /etc/rc.subr

name="tinyproxy"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/$name.conf"

load_rc_config $name
run_rc_command "$1"
