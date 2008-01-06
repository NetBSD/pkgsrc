#!@RCD_SCRIPTS_SHELL@
#
# Startup script for Zeo @ZOPE_VERSION@ server.
#
# $NetBSD: zeo.sh,v 1.1 2008/01/06 15:51:40 taca Exp $
#

# PROVIDE: zeo@ZOPE_VERSION@
# REQUIRE: DAEMON
# BEFORE: @ZOPE_PKG@
#
# You will need to set some variables in /etc/rc.conf to start one
# or more instances.
#
# zeo@ZOPE_VERSION@@RCVAR_SUFFIX@ : bool
#   Enable Zeo ("YES") or not ("NO", the default).
#
# zeo@ZOPE_VERSION@_encoding : list
#   Default character encoding for zeo@ZOPE_VERSION@ (default is "utf-8").
#
# zeo@ZOPE_VERSION@_instances : list
#   List of dirs with Zeo's instances ("" by default).
#

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="zeo@ZOPE_VERSION@"
rcvar="$name@RCVAR_SUFFIX@"
version="@ZOPE_FULL_VERSION@"
zeo_name="Zope ${version}"

zeo@ZOPE_VERSION@ctl () {
	cmd = $1

	set ${zeo@ZOPE_VERSION@_encoding}
	for instance in $zeo@ZOPE_VERSION@_instances; do
		if [ "$1" ]; then
			ZOPE@ZOPE_VERSION@_DEFAULT_ENCODING="$1"
			export ZOPE@ZOPE_VERSION@_DEFAULT_ENCODING
		else
			unset ZOPE@ZOPE_VERSION@_DEFAULT_ENCODING
		fi
		if [ -d ${instance} ]; then
			echo -n "  Zeo instance ${instance} -> "
			${instance}/bin/zeoctl ${cmd}
		fi
		shift
	done
}

zeo@ZOPE_VERSION@_start () {
    echo "Starting ${zeo_name}:"
    zeo@ZOPE_VERSION@ctl "start"
}

zeo@ZOPE_VERSION@_stop () {
    echo "Stopping ${zeo_name}:"
    zeo@ZOPE_VERSION@ctl "stop"
}

zeo@ZOPE_VERSION@_restart () {
    echo "Restarting ${zeo_name}:"
    zeo@ZOPE_VERSION@ctl "restart"
}

  start_cmd="zeo@ZOPE_VERSION@_start"
   stop_cmd="zeo@ZOPE_VERSION@_stop"
restart_cmd="zeo@ZOPE_VERSION@_restart"

load_rc_config $name

: ${zeo@ZOPE_VERSION@_@RCVAR_SUFFIX@="NO"}
: ${zeo@ZOPE_VERSION@_encoding="utf-8"}
: ${zeo@ZOPE_VERSION@_instances=""}

cmd="$1"
[ $# -gt 0 ] && shift
[ -n  "$*" ] && zeo@ZOPE_VERSION@_instances="$*"

if [ "${zeo@ZOPE_VERSION@_encoding}" ]; then
	ZOPE@ZOPE_VERSION@_DEFAULT_ENCODING=${@ZOPE_PKG@_encoding}
	export ZOPE@ZOPE_VERSION@_DEFAULT_ENCODING
fi

run_rc_command "${cmd}"
