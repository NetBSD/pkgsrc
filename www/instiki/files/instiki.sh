#!/bin/sh
#
# $NetBSD: instiki.sh,v 1.1.1.1 2005/01/15 16:18:39 minskim Exp $
#

# PROVIDE: instiki

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="instiki"
rcvar=${name}
command="@PREFIX@/share/instiki/${name}"
command_args="-t @VARBASE@/instiki"
command_interpreter="@RUBY@"

if [ -f /etc/rc.subr ]; then
	load_rc_config ${name}
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	${command} ${instiki_flags} ${command_args}
fi
