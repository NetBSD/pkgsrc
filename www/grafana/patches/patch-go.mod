$NetBSD: patch-go.mod,v 1.3 2023/02/21 10:14:29 jperkin Exp $

Use bluge fork to support illumos.
https://github.com/blugelabs/bluge/pull/139

--- go.mod.orig	2023-01-26 14:38:58.000000000 +0000
+++ go.mod
@@ -108,7 +108,7 @@ require (
 	go.opentelemetry.io/otel/trace v1.7.0
 	golang.org/x/crypto v0.0.0-20220622213112-05595931fe9d
 	golang.org/x/exp v0.0.0-20220613132600-b0d781184e0d
-	golang.org/x/net v0.1.0 // indirect
+	golang.org/x/net v0.1.0
 	golang.org/x/oauth2 v0.0.0-20220630143837-2104d58473e0
 	golang.org/x/sync v0.1.0
 	golang.org/x/time v0.0.0-20220609170525-579cf78fd858
@@ -271,6 +271,7 @@ require (
 	cloud.google.com/go v0.102.0 // indirect
 	github.com/Azure/azure-pipeline-go v0.2.3 // indirect
 	github.com/armon/go-metrics v0.3.10 // indirect
+	github.com/blugelabs/ice/v2 v2.0.1 // indirect
 	github.com/bmatcuk/doublestar v1.1.1 // indirect
 	github.com/buildkite/yaml v2.1.0+incompatible // indirect
 	github.com/cpuguy83/go-md2man/v2 v2.0.2 // indirect
@@ -386,3 +387,5 @@ replace github.com/prometheus/alertmanag
 replace google.golang.org/grpc => google.golang.org/grpc v1.45.0
 
 replace google.golang.org/genproto => google.golang.org/genproto v0.0.0-20220421151946-72621c1f0bd3
+
+replace github.com/blugelabs/bluge => github.com/jperkin/bluge v0.0.0-20221115155924-ffd91b43c395
