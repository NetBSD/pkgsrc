#!@RCD_SCRIPTS_SHELL@
#
# PROVIDE: varnishd
# REQUIRE: DAEMON

. /etc/rc.subr

name="varnishd"
rcvar=$name
command="@PREFIX@/sbin/varnishd"

load_rc_config $name
run_rc_command "$1"
