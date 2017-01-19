#!/bin/sh
#
# $NetBSD: sogod.sh,v 1.1 2017/01/19 23:45:33 wiedi Exp $
#

# PROVIDE: sogod
# REQUIRE: DAEMON
# BEFORE: apache

$_rc_subr_loaded . /etc/rc.subr

name="sogod"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="@SOGORUNDIR@/${name}.pid"
logfile="@SOGORUNDIR@/${name}.log"
sogouser=@SOGOUSER@
command_args="-WOPidFile ${pidfile} -WOLogFile ${logfile}"
start_precmd="sogod_precmd"
start_cmd="sogod_start"

sogod_precmd()
{
    test -f @PREFIX@/etc/GNUstep.conf || {
        echo "Cannot find @PREFIX@/etc/GNUstep.conf"
        exit 1
    }
    . @PREFIX@/etc/GNUstep.conf

    test -f @PREFIX@/share/GNUstep/Makefiles/GNUstep.sh || {
        echo "Cannot find @PREFIX@/share/GNUstep/Makefiles/GNUstep.sh"
        exit 1
    }
    . @PREFIX@/share/GNUstep/Makefiles/GNUstep.sh
}

sogod_start()
{ 
    echo "Starting $name: "
    su -m ${sogouser} -c "${command} ${command_args}"
} 

load_rc_config $name
run_rc_command "$1"
