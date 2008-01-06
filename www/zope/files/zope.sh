#!@RCD_SCRIPTS_SHELL@
#
# Startup script for Zope @ZOPE_VERSION@ server.
#
# $NetBSD: zope.sh,v 1.1 2008/01/06 15:51:40 taca Exp $
#

# PROVIDE: @ZOPE_PKG@
# REQUIRE: DAEMON

# You will need to set some variables in /etc/rc.conf to start Zope
#
# @ZOPE_PKG@@RCVAR_SUFFIX@ : bool
#   Enable Zope ("YES") or not ("NO", the default).
#
# @ZOPE_PKG@_encoding : list
#   Default character encoding for @ZOPE_PKG@ (default is "utf-8").
#   You can specify single character encoding for all Zope instances
#   or specify a list for each Zope instance.  "none" means specify
#   nothing.
#
# @ZOPE_PKG@_instances : list
#   List of dirs with Zope's instances ("" by default).
#

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="@ZOPE_PKG@"
rcvar="$name@RCVAR_SUFFIX@"
version="@ZOPE_FULL_VERSION@"
zope_name="Zope ${version}"
start_cmd="@ZOPE_PKG@_start"
stop_cmd="@ZOPE_PKG@_stop"
restart_cmd="@ZOPE_PKG@_restart"

@ZOPE_PKG@ctl () {
	cmd=$1

	for encoding in ${@ZOPE_PKG@_encoding}; do
		if [ "$encoding" ]; then
			ZOPE@ZOPE_VERSION@_DEFAULT_ENCODING="$encoding"
			export ZOPE@ZOPE_VERSION@_DEFAULT_ENCODING
		else
			unset ZOPE@ZOPE_VERSION@_DEFAULT_ENCODING
		fi
		for instance in ${@ZOPE_PKG@_instances}; do
			if [ -d ${instance} ]; then
				echo -n "  Zope instance ${instance} -> "
				${instance}/bin/zopectl ${cmd}
			fi
		done
	done
}

@ZOPE_PKG@_start () {
	echo "Starting ${zope_name}:"
	@ZOPE_PKG@ctl "start"
}

@ZOPE_PKG@_stop () {
	echo "Stopping ${zope_name}:"
	@ZOPE_PKG@ctl "stop"
}

@ZOPE_PKG@_restart () {
	echo "Restarting ${zope_name}:"
	@ZOPE_PKG@ctl "restart"
}

load_rc_config $name

: ${@ZOPE_PKG@@RCVAR_SUFFIX@="NO"}
: ${@ZOPE_PKG@_encoding="utf-8"}
: ${@ZOPE_PKG@_instances=""}

cmd="$1"
[ $# -gt 0 ] && shift
[ -n  "$*" ] && @ZOPE_PKG@_instances="$*"

run_rc_command "${cmd}"
