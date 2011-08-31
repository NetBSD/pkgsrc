#!@RCD_SCRIPTS_SHELL@
#
# PROVIDE: varnishncsa
# REQUIRE: varnishd

. /etc/rc.subr

name="varnishncsa"
rcvar=$name
command="@PREFIX@/bin/varnishncsa"
command_args="-D"

load_rc_config $name
run_rc_command "$1"
