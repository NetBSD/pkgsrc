#!/bin/sh
#
# Startup script for Zeo server.
#
# $NetBSD: zeo29.sh,v 1.1 2006/08/17 11:57:25 darcy Exp $
#

# PROVIDE: zeo29
# REQUIRE: DAEMON
# BEFORE: zope29
#
# You will need to set some variables in /etc/rc.conf to start one
# or more instances.
#
# zeo29_enable : bool
#   Enable Zeo ("YES") or not ("NO", the default).
#
# zeo29_instances : list
#   List of dirs with Zeo's instances ("" by default).
#

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="zeo29"
rcvar=`set_rcvar`

zeo29ctl () {
    for instance in $zeo29_instances; do
	if [ -d ${instance} ]; then
	    echo -n "  Zeo instance ${instance} -> "
	    ${instance}/bin/zeoctl "$1"
	fi
    done
}

zeo29_start () {
    echo "Starting Zeo 2.9:"
    zeo29ctl "start"
}

zeo29_stop () {
    echo "Stopping Zeo 2.9:"
    zeo29ctl "stop"
}

zeo29_restart () {
    echo "Restarting Zeo 2.9:"
    zeo29ctl "restart"
}

  start_cmd="zeo29_start"
   stop_cmd="zeo29_stop"
restart_cmd="zeo29_restart"

load_rc_config $name

: ${zeo29_enable="NO"}
: ${zeo29_instances=""}

cmd="$1"
[ $# -gt 0 ] && shift
[ -n  "$*" ] && zeo29_instances="$*"

run_rc_command "${cmd}"
