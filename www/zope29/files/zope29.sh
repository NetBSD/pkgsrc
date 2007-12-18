#!@RCD_SCRIPTS_SHELL@
#
# Startup script for Zope server.
#
# $NetBSD: zope29.sh,v 1.2 2007/12/18 15:31:12 taca Exp $
#

# PROVIDE: zope29
# REQUIRE: DAEMON

# You will need to set some variables in /etc/rc.conf to start Zope
#
# zope29@RCVAR_SUFFIX@ : bool
#   Enable Zope ("YES") or not ("NO", the default).
#
# zope29_encoding : list
#   Default character encoding for zope29 (default is "utf-8").
#   You can specify single character encoding for all Zope instances
#   or specify a list for each Zope instance.  "none" means specify
#   nothing.
#
# zope29_instances : list
#   List of dirs with Zope's instances ("" by default).
#

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="zope29"
rcvar="$name@RCVAR_SUFFIX@"
version="@VER@"
zope_name="Zope ${version}"
start_cmd="zope29_start"
stop_cmd="zope29_stop"
restart_cmd="zope29_restart"

zope29ctl () {
	cmd=$1

	for encoding in ${zope29_encoding}; do
		if [ "$encoding" ]; then
			ZOPE29_DEFAULT_ENCODING="$encoding"
			export ZOPE29_DEFAULT_ENCODING
		else
			unset ZOPE29_DEFAULT_ENCODING
		fi
		for instance in ${zope29_instances}; do
			if [ -d ${instance} ]; then
				echo -n "  Zope instance ${instance} -> "
				${instance}/bin/zopectl ${cmd}
			fi
		done
	done
}

zope29_start () {
	echo "Starting ${zope_name}:"
	zope29ctl "start"
}

zope29_stop () {
	echo "Stopping ${zope_name}:"
	zope29ctl "stop"
}

zope29_restart () {
	echo "Restarting ${zope_name}:"
	zope29ctl "restart"
}

load_rc_config $name

: ${zope29@RCVAR_SUFFIX@="NO"}
: ${zope29_encoding="utf-8"}
: ${zope29_instances=""}

cmd="$1"
[ $# -gt 0 ] && shift
[ -n  "$*" ] && zope29_instances="$*"

run_rc_command "${cmd}"
