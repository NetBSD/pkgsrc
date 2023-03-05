$NetBSD: patch-go.mod,v 1.4 2023/03/05 21:22:45 triaxx Exp $

Use bluge fork to support illumos.
https://github.com/blugelabs/bluge/pull/139

--- go.mod.orig	2023-03-01 22:08:07.000000000 +0000
+++ go.mod
@@ -289,6 +289,7 @@ require (
 	github.com/Azure/go-ansiterm v0.0.0-20210617225240-d185dfc1b5a1 // indirect
 	github.com/Masterminds/goutils v1.1.1 // indirect
 	github.com/armon/go-metrics v0.4.1 // indirect
+	github.com/blugelabs/ice/v2 v2.0.1 // indirect
 	github.com/bmatcuk/doublestar v1.1.1 // indirect
 	github.com/buildkite/yaml v2.1.0+incompatible // indirect
 	github.com/containerd/containerd v1.6.8 // indirect
@@ -430,3 +431,5 @@ replace github.com/prometheus/alertmanag
 replace google.golang.org/grpc => google.golang.org/grpc v1.45.0
 
 replace google.golang.org/genproto => google.golang.org/genproto v0.0.0-20220421151946-72621c1f0bd3
+
+replace github.com/blugelabs/bluge => github.com/jperkin/bluge v0.0.0-20221115155924-ffd91b43c395
