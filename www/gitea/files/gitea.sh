#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: gitea.sh,v 1.5 2022/03/23 23:41:14 khorben Exp $
#
# PROVIDE: gitea
# REQUIRE: DAEMON
#
# You will need to set some variables in @SYSCONFBASE@/rc.conf to start gitea:
#
# gitea=YES

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr

name="gitea"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/conf/app.ini"
command="@PREFIX@/sbin/gitea"
command_args="--config @PKG_SYSCONFDIR@/conf/app.ini web > /dev/null &"

gitea_env="GITEA_WORK_DIR=@GITEA_SHARE_DIR@"
gitea_env="${gitea_env} GITEA_CUSTOM=@PKG_SYSCONFDIR@"
gitea_env="${gitea_env} HOME=@GITEA_USER_HOME@"
gitea_env="${gitea_env} USER=@GITEA_USER@"

gitea_user="@GITEA_USER@"
gitea_group="@GITEA_GROUP@"

cd /

load_rc_config $name
run_rc_command "$1"
