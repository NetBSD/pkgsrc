#!/bin/sh
#
# $NetBSD: gdm.sh,v 1.2 2004/01/22 09:16:59 jmmv Exp $
#

# PROVIDE: gdm
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="gdm"
rcvar=${name}
command="@PREFIX@/bin/${name}"
pidfile="/var/run/${name}.pid"
procname="@PREFIX@/bin/gdm-binary"
required_files="@PKG_SYSCONFDIR@/gdm/gdm.conf"
extra_commands="reload"

if [ -f /etc/rc.subr ]; then
	load_rc_config ${name}
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${gdm_flags} ${command_args}
fi
