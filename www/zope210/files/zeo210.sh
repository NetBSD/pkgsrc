#!@RCD_SCRIPTS_SHELL@
#
# Startup script for Zeo server.
#
# $NetBSD: zeo210.sh,v 1.1.1.1 2007/12/18 15:35:28 taca Exp $
#

# PROVIDE: zeo210
# REQUIRE: DAEMON
# BEFORE: zope210
#
# You will need to set some variables in /etc/rc.conf to start one
# or more instances.
#
# zeo210@RCVAR_SUFFIX@ : bool
#   Enable Zeo ("YES") or not ("NO", the default).
#
# zeo210_encoding : string
#   Default character encoding for zeo210 (default is "utf-8").
#
# zeo210_instances : list
#   List of dirs with Zeo's instances ("" by default).
#

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="zeo210"
rcvar="$name@RCVAR_SUFFIX@"
version="@VER@"
zeo_name="Zope ${version}"

zeo210ctl () {
    for instance in $zeo210_instances; do
	if [ -d ${instance} ]; then
	    echo -n "  Zeo instance ${instance} -> "
	    ${instance}/bin/zeoctl "$1"
	fi
    done
}

zeo210_start () {
    echo "Starting ${zeo_name}:"
    zeo210ctl "start"
}

zeo210_stop () {
    echo "Stopping ${zeo_name}:"
    zeo210ctl "stop"
}

zeo210_restart () {
    echo "Restarting ${zeo_name}:"
    zeo210ctl "restart"
}

  start_cmd="zeo210_start"
   stop_cmd="zeo210_stop"
restart_cmd="zeo210_restart"

load_rc_config $name

: ${zeo210_@RCVAR_SUFFIX@="NO"}
: ${zeo210_encoding="utf-8"}
: ${zeo210_instances=""}

cmd="$1"
[ $# -gt 0 ] && shift
[ -n  "$*" ] && zeo210_instances="$*"

if [ "${zeo210_encoding}" ]; then
	ZOPE210_DEFAULT_ENCODING=${zope210_encoding}
	export ZOPE210_DEFAULT_ENCODING
fi

run_rc_command "${cmd}"
