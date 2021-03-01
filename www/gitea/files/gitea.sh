#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: gitea.sh,v 1.3 2021/03/01 23:47:09 khorben Exp $
#
# PROVIDE: gitea
# REQUIRE: DAEMON

. /etc/rc.subr

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

load_rc_config $name
run_rc_command "$1"
