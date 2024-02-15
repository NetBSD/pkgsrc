$NetBSD: patch-pkg_cmd_grafana-server_commands_flags.go,v 1.1 2024/02/15 13:24:06 wiz Exp $

Use pkgsrc layout.
from: patch-pkg_cmd_grafana-server_main.go,v 1.1 2020/08/27 13:05:20 jperkin Exp

--- pkg/cmd/grafana-server/commands/flags.go.orig	2023-11-20 09:27:24.000000000 +0000
+++ pkg/cmd/grafana-server/commands/flags.go
@@ -21,22 +21,25 @@ var (
 var commonFlags = []cli.Flag{
 	&cli.StringFlag{
 		Name:        "config",
+		Value:       "@PKG_SYSCONFDIR@/grafana.conf",
 		Usage:       "Path to config file",
 		Destination: &ConfigFile,
 	},
 	&cli.StringFlag{
 		Name:        "homepath",
+		Value:       "@PREFIX@/share/grafana",
 		Usage:       "Path to Grafana install/home path, defaults to working directory",
 		Destination: &HomePath,
 	},
 	&cli.StringFlag{
 		Name:        "pidfile",
+		Value:       "@DATADIR@/grafana.pid",
 		Usage:       "Path to Grafana pid file",
 		Destination: &PidFile,
 	},
 	&cli.StringFlag{
 		Name:        "packaging",
-		Value:       "unknown",
+		Value:       "pkgsrc",
 		Usage:       "describes the way Grafana was installed",
 		Destination: &Packaging,
 	},
