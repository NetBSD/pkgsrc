#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: privoxy.sh,v 1.3 2003/07/12 15:11:39 salo Exp $
#

# PROVIDE: privoxy
# REQUIRE: DAEMON

. /etc/rc.subr

name="privoxy"
rcvar=$name
command="/usr/pkg/sbin/${name}"
pidfile="/var/run/${name}.pid"
pconfig="@PKG_SYSCONFDIR@/config"
puser="@PRIVOXY_USER@"
required_files="$pconfig"
command_args="--pidfile ${pidfile} --user ${puser} ${pconfig} 2>/dev/null"

load_rc_config $name
run_rc_command "$1"
