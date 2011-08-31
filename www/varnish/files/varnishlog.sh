#!@RCD_SCRIPTS_SHELL@
#
# PROVIDE: varnishlog
# REQUIRE: varnishd

. /etc/rc.subr

name="varnishlog"
rcvar=$name
command="@PREFIX@/bin/varnishlog"
command_args="-D"

load_rc_config $name
run_rc_command "$1"
