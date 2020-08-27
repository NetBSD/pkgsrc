$NetBSD: patch-pkg_cmd_grafana-server_main.go,v 1.1 2020/08/27 13:05:20 jperkin Exp $

Use pkgsrc layout.

--- pkg/cmd/grafana-server/main.go.orig	2020-08-06 08:44:32.000000000 +0000
+++ pkg/cmd/grafana-server/main.go
@@ -39,9 +39,9 @@ var buildstamp string
 
 func main() {
 	var (
-		configFile = flag.String("config", "", "path to config file")
-		homePath   = flag.String("homepath", "", "path to grafana install/home path, defaults to working directory")
-		pidFile    = flag.String("pidfile", "", "path to pid file")
+		configFile = flag.String("config", "@PKG_SYSCONFDIR@/grafana.conf", "path to config file")
+		homePath   = flag.String("homepath", "@PREFIX@/share/grafana", "path to grafana install/home path, defaults to working directory")
+		pidFile    = flag.String("pidfile", "@DATADIR@/grafana.pid", "path to pid file")
 		packaging  = flag.String("packaging", "unknown", "describes the way Grafana was installed")
 
 		v           = flag.Bool("v", false, "prints current version and exits")
