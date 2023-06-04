#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: mailman-web.sh,v 1.1 2023/06/04 03:42:22 markd Exp $
#
#  run django_q task queue for hyperkitty
#
# PROVIDE: mailman_web
# REQUIRE: mail

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="mailman_web"
rcvar=$name
command="@PREFIX@/bin/mailman-web"
command_args="qcluster"
command_interpreter="@PYTHONBIN@"
start_cmd="mailman_web_doit"

mailman_web_doit()
{
	@SU@ -m @MAILMAN_USER@ -c "${command} ${command_args} &"
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
        [ "$1" eq "start" ] && $start_cmd
fi
