$NetBSD: patch-go.mod,v 1.1 2022/11/15 16:45:26 jperkin Exp $

Use bluge fork to support illumos.
https://github.com/blugelabs/bluge/pull/139

--- go.mod.orig	2022-11-08 10:38:42.000000000 +0000
+++ go.mod
@@ -264,6 +264,7 @@ require (
 require (
 	cloud.google.com/go v0.100.2 // indirect
 	github.com/armon/go-metrics v0.3.10 // indirect
+	github.com/blugelabs/ice/v2 v2.0.1 // indirect
 	github.com/bmatcuk/doublestar v1.1.1 // indirect
 	github.com/buildkite/yaml v2.1.0+incompatible // indirect
 	github.com/cpuguy83/go-md2man/v2 v2.0.2 // indirect
@@ -370,3 +371,5 @@ replace xorm.io/xorm => github.com/grafa
 // Use our fork of the upstream alertmanagers.
 // This is required in order to get notification delivery errors from the receivers API.
 replace github.com/prometheus/alertmanager => github.com/grafana/prometheus-alertmanager v0.24.1-0.20221012142027-823cd9150293
+
+replace github.com/blugelabs/bluge => github.com/jperkin/bluge v0.0.0-20221115155924-ffd91b43c395
