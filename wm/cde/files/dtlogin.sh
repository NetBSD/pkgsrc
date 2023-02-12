#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dtlogin.sh,v 1.1 2023/02/12 16:34:15 vins Exp $
#
# PROVIDE: dtlogin
# REQUIRE: DAEMON LOGIN
# KEYWORD: shutdown
#

. /etc/rc.subr

name="dtlogin"
rcvar=$name
command="@PREFIX@/dt/bin/dtlogin"
command_args="-daemon"
pidfile="@VARBASE@/dt/Xpid"
extra_commands="reload"

load_rc_config $name


start_precmd=dtlogin_prestart

dtlogin_prestart()
{
	if ! [ -f "@PREFIX@/etc/X11/Xwrapper.config" ]; then
			echo "If dtlogin fails to start:"
			echo "# echo allowed_users=anybody >> @PREFIX@/etc/X11/Xwrapper.config"
	fi
}

run_rc_command "$1"
