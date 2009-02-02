#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: privoxy.sh,v 1.4 2009/02/02 20:00:40 jnemeth Exp $
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
pgroup="@PRIVOXY_GROUP@"
required_files="$pconfig"
command_args="--pidfile ${pidfile} --user ${puser}.${pgroup} ${pconfig} 2>/dev/null"

load_rc_config $name
run_rc_command "$1"
