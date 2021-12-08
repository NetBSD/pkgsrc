$NetBSD: patch-pkg_cmd_grafana-server_commands_cli.go,v 1.1 2021/12/08 01:51:47 tnn Exp $

Use pkgsrc layout.
from: patch-pkg_cmd_grafana-server_main.go,v 1.1 2020/08/27 13:05:20 jperkin Exp

--- pkg/cmd/grafana-server/commands/cli.go.orig	2021-12-06 07:21:15.000000000 +0000
+++ pkg/cmd/grafana-server/commands/cli.go
@@ -49,9 +49,9 @@ func (e exitWithCode) Error() string {
 
 func RunServer(opt ServerOptions) int {
 	var (
-		configFile = serverFs.String("config", "", "path to config file")
-		homePath   = serverFs.String("homepath", "", "path to grafana install/home path, defaults to working directory")
-		pidFile    = serverFs.String("pidfile", "", "path to pid file")
+		configFile = serverFs.String("config", "@PKG_SYSCONFDIR@/grafana.conf", "path to config file")
+		homePath   = serverFs.String("homepath", "@PREFIX@/share/grafana", "path to grafana install/home path, defaults to working directory")
+		pidFile    = serverFs.String("pidfile", "@DATADIR@/grafana.pid", "path to pid file")
 		packaging  = serverFs.String("packaging", "unknown", "describes the way Grafana was installed")
 
 		v           = serverFs.Bool("v", false, "prints current version and exits")
