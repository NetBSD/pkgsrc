#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: kdm.sh,v 1.1 2004/01/15 10:15:14 markd Exp $
#

# PROVIDE: kdm
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="kdm"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="/var/run/xdm.pid"
required_files="@PREFIX@/share/kde/config/kdm/kdmrc"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${kdm_flags} ${command_args}
fi
