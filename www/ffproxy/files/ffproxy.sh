#!/bin/sh
#

# PROVIDE: ffproxy
# REQUIRE: DAEMON LOGIN

$_rc_subr_loaded . /etc/rc.subr

name="ffproxy"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="@VARBASE@/run/${name}.pid"

load_rc_config $name
run_rc_command "$1"
