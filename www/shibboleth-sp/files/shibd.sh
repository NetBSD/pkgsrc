#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: shibd.sh,v 1.2 2015/10/23 07:35:07 pettai Exp $
#
# PROVIDE: shibd
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
        . /etc/rc.subr
fi

name="shibd"
rcvar=$name
command="@PREFIX@/sbin/shibd"
pidfile="/var/run/shibboleth/shibd.pid"
start_precmd="shibd_precmd"
command_args="-p $pidfile"

shibd_precmd()
{
    if [ ! -d /var/run/shibboleth ]; then
        mkdir -p -m 755 /var/run/shibboleth
    fi
    if [ -f /var/run/shibboleth/shibd.sock ]; then
        rm -f /var/run/shibboleth/shibd.sock
    fi
}

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
        run_rc_command "$1"
else
        echo -n " ${name}"
        ${command} ${shibd_flags} ${command_args}
fi
