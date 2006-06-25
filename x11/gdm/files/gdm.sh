#!/bin/sh
#
# $NetBSD: gdm.sh,v 1.5 2006/06/25 17:16:33 jmmv Exp $
#

# PROVIDE: gdm
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="gdm"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
procname="@PREFIX@/sbin/gdm-binary"
required_files="@PKG_SYSCONFDIR@/custom.conf"
extra_commands="reload"

if [ -f /etc/rc.subr ]; then
	load_rc_config ${name}
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${gdm_flags} ${command_args}
fi
