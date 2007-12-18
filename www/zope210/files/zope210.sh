#!@RCD_SCRIPTS_SHELL@
#
# Startup script for Zope server.
#
# $NetBSD: zope210.sh,v 1.1.1.1 2007/12/18 15:35:28 taca Exp $
#

# PROVIDE: zope210
# REQUIRE: DAEMON

# You will need to set some variables in /etc/rc.conf to start Zope
#
# zope210@RCVAR_SUFFIX@ : bool
#   Enable Zope ("YES") or not ("NO", the default).
#
# zope210_encoding : list
#   Default character encoding for zope210 (default is "utf-8").
#   You can specify single character encoding for all Zope instances
#   or specify a list for each Zope instance.  "none" means specify
#   nothing.
#
# zope210_instances : list
#   List of dirs with Zope's instances ("" by default).
#

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="zope210"
rcvar="$name@RCVAR_SUFFIX@"
version="@VER@"
zope_name="Zope ${version}"
start_cmd="zope210_start"
stop_cmd="zope210_stop"
restart_cmd="zope210_restart"

zope210ctl () {
	cmd=$1

	for encoding in ${zope210_encoding}; do
		if [ "$encoding" ]; then
			ZOPE210_DEFAULT_ENCODING="$encoding"
			export ZOPE210_DEFAULT_ENCODING
		else
			unset ZOPE210_DEFAULT_ENCODING
		fi
		for instance in ${zope210_instances}; do
			if [ -d ${instance} ]; then
				echo -n "  Zope instance ${instance} -> "
				${instance}/bin/zopectl ${cmd}
			fi
		done
	done
}

zope210_start () {
    echo "Starting ${zope_name}:"
    zope210ctl "start"
}

zope210_stop () {
    echo "Stopping ${zope_name}:"
    zope210ctl "stop"
}

zope210_restart () {
    echo "Restarting ${zope_name}:"
    zope210ctl "restart"
}

load_rc_config $name

: ${zope210@RCVAR_SUFFIX@="NO"}
: ${zope210_encoding="utf-8"}
: ${zope210_instances=""}

cmd="$1"
[ $# -gt 0 ] && shift
[ -n  "$*" ] && zope210_instances="$*"

run_rc_command "${cmd}"
