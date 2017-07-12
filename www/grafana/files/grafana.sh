#!@RCD_SCRIPTS_SHELL@

# PROVIDE: grafana
# REQUIRE: DAEMON
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]
then
        . /etc/rc.subr
fi

name="grafana"
rcvar=$name
grafana_user="@GRAFANA_USER@"
grafana_group="@GRAFANA_GROUP@"
grafana_chdir="@PREFIX@/share/grafana"
pidfile="@VARBASE@/lib/grafana/data/grafana.pid"
command="@PREFIX@/bin/grafana-server"
command_args="-homepath ${grafana_chdir} -config /usr/pkg/etc/grafana.conf -pidfile ${pidfile} < /dev/null > /dev/null 2>&1 &"

load_rc_config $name
run_rc_command "$1"
