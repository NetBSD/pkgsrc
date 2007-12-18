#!@RCD_SCRIPTS_SHELL@
#
# Startup script for Zeo server.
#
# $NetBSD: zeo29.sh,v 1.2 2007/12/18 15:31:12 taca Exp $
#

# PROVIDE: zeo29
# REQUIRE: DAEMON
# BEFORE: zope29
#
# You will need to set some variables in /etc/rc.conf to start one
# or more instances.
#
# zeo29@RCVAR_SUFFIX@ : bool
#   Enable Zeo ("YES") or not ("NO", the default).
#
# zeo29_encoding : list
#   Default character encoding for zeo29 (default is "utf-8").
#
# zeo29_instances : list
#   List of dirs with Zeo's instances ("" by default).
#

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="zeo29"
rcvar="$name@RCVAR_SUFFIX@"
version="@VER@"
zeo_name="Zope ${version}"

zeo29ctl () {
	cmd = $1

	set ${zeo29_encoding}
	for instance in $zeo29_instances; do
		if [ "$1" ]; then
			ZOPE29_DEFAULT_ENCODING="$1"
			export ZOPE29_DEFAULT_ENCODING
		else
			unset ZOPE29_DEFAULT_ENCODING
		fi
		if [ -d ${instance} ]; then
			echo -n "  Zeo instance ${instance} -> "
			${instance}/bin/zeoctl ${cmd}
		fi
		shift
	done
}

zeo29_start () {
    echo "Starting ${zeo_name}:"
    zeo29ctl "start"
}

zeo29_stop () {
    echo "Stopping ${zeo_name}:"
    zeo29ctl "stop"
}

zeo29_restart () {
    echo "Restarting ${zeo_name}:"
    zeo29ctl "restart"
}

  start_cmd="zeo29_start"
   stop_cmd="zeo29_stop"
restart_cmd="zeo29_restart"

load_rc_config $name

: ${zeo29_@RCVAR_SUFFIX@="NO"}
: ${zeo29_encoding="utf-8"}
: ${zeo29_instances=""}

cmd="$1"
[ $# -gt 0 ] && shift
[ -n  "$*" ] && zeo29_instances="$*"

if [ "${zeo29_encoding}" ]; then
	ZOPE29_DEFAULT_ENCODING=${zope29_encoding}
	export ZOPE29_DEFAULT_ENCODING
fi

run_rc_command "${cmd}"
