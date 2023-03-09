$NetBSD: patch-pkg_cmd_grafana-server_commands_cli.go,v 1.3 2023/03/09 18:02:00 triaxx Exp $

Use pkgsrc layout.
from: patch-pkg_cmd_grafana-server_main.go,v 1.1 2020/08/27 13:05:20 jperkin Exp

--- pkg/cmd/grafana-server/commands/cli.go.orig	2023-03-02 20:28:42.000000000 +0000
+++ pkg/cmd/grafana-server/commands/cli.go
@@ -43,14 +43,17 @@ func ServerCommand(version, commit, buil
 		Flags: []cli.Flag{
 			&cli.StringFlag{
 				Name:  "config",
+				Value: "@PKG_SYSCONFDIR@/grafana.conf",
 				Usage: "Path to config file",
 			},
 			&cli.StringFlag{
 				Name:  "homepath",
+				Value: "@PREFIX@/share/grafana",
 				Usage: "Path to Grafana install/home path, defaults to working directory",
 			},
 			&cli.StringFlag{
 				Name:  "pidfile",
+				Value: "@DATADIR@/grafana.pid",
 				Usage: "Path to Grafana pid file",
 			},
 			&cli.StringFlag{
