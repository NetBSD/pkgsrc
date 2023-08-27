$NetBSD: patch-go.mod,v 1.5 2023/08/27 12:09:56 tnn Exp $

Use bluge fork to support illumos.
https://github.com/blugelabs/bluge/pull/139

--- go.mod.orig	2023-08-23 17:05:28.000000000 +0000
+++ go.mod
@@ -298,6 +298,7 @@ require (
 	github.com/apapsch/go-jsonmerge/v2 v2.0.0 // indirect
 	github.com/armon/go-metrics v0.4.1 // indirect
 	github.com/blang/semver/v4 v4.0.0 // indirect
+	github.com/blugelabs/ice/v2 v2.0.1 // indirect
 	github.com/bmatcuk/doublestar v1.1.1 // indirect
 	github.com/buildkite/yaml v2.1.0+incompatible // indirect
 	github.com/bwmarrin/snowflake v0.3.0 // indirect
@@ -491,3 +492,5 @@ replace google.golang.org/grpc => google
 replace github.com/lib/pq => github.com/lib/pq v1.10.6
 
 exclude github.com/mattn/go-sqlite3 v2.0.3+incompatible
+
+replace github.com/blugelabs/bluge => github.com/jperkin/bluge v0.0.0-20221115155924-ffd91b43c395
