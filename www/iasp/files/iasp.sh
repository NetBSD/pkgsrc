#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: iasp.sh,v 1.1.1.1 2003/01/01 07:03:42 jlam Exp $
#
# PROVIDE: iasp
# REQUIRE: DAEMON
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="iasp"
rcvar=$name
start_cmd=iasp_start
stop_cmd=iasp_stop

iasp_start()
{
	@IASP@/start-server.sh &
	sleep 2
}

iasp_stop()
{
	@IASP@/stop-server.sh
}

if [ -f /etc/rc.subr -a -f /etc/rc.conf -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]
then
        load_rc_config $name
        run_rc_command "$1"
else
        eval ${start_cmd}
fi
