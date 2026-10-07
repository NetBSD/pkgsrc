#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: tinyproxy.sh,v 1.5 2026/10/07 19:33:33 chuck Exp $
#

# PROVIDE: tinyproxy
# REQUIRE: DAEMON

. /etc/rc.subr

name="tinyproxy"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="@VARBASE@/run/tinyproxy/${name}.pid"
required_files="@PKG_SYSCONFDIR@/${name}.conf"
start_precmd="tinyproxy_precmd"

tinyproxy_precmd()
{
    if [ ! -d @VARBASE@/run/tinyproxy ]; then
        mkdir -p -m 755 @VARBASE@/run/tinyproxy
    fi
    chown @TINYPROXY_USER@:@TINYPROXY_GROUP@ @VARBASE@/run/tinyproxy
}

load_rc_config $name
run_rc_command "$1"
