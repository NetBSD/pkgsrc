$NetBSD: patch-go.mod,v 1.9 2024/05/13 15:59:54 wiz Exp $

Bluge upstream is dead, and k8s refuse to support non-Linux platforms, so we're
stuck carrying these changes.  Previous pull requests:

  https://github.com/blugelabs/bluge/pull/139
  https://github.com/kubernetes/kubernetes/pull/120498

Here's how to generate these patches:

  $ cd $WRKSRC
  $ cp -p go.mod go.mod.orig
  $ cp -p go.sum go.sum.orig
  $ go get github.com/jperkin/bluge@master
  $ go mod edit --replace=github.com/blugelabs/bluge=github.com/jperkin/bluge@<version output>
  $ go get github.com/jperkin/apiserver@master
  $ go mod edit --replace=k8s.io/apiserver=github.com/jperkin/apiserver@<version output>
  $ go mod tidy

Then show-go-modules and mkpatches as normal.

--- go.mod.orig	2024-04-10 13:19:40.000000000 +0000
+++ go.mod
@@ -487,6 +487,7 @@ require github.com/spyzhov/ajson v0.9.0
 require github.com/fullstorydev/grpchan v1.1.1 // @grafana/backend-platform
 
 require (
+	github.com/blugelabs/ice/v2 v2.0.1 // indirect
 	github.com/bufbuild/protocompile v0.4.0 // indirect
 	github.com/grafana/sqlds/v3 v3.2.0 // indirect
 	github.com/jhump/protoreflect v1.15.1 // indirect
@@ -520,3 +521,7 @@ replace xorm.io/xorm => ./pkg/util/xorm
 replace github.com/prometheus/alertmanager => github.com/grafana/prometheus-alertmanager v0.25.1-0.20240208102907-e82436ce63e6
 
 exclude github.com/mattn/go-sqlite3 v2.0.3+incompatible
+
+replace github.com/blugelabs/bluge => github.com/jperkin/bluge v0.0.0-20221115155924-ffd91b43c395
+
+replace k8s.io/apiserver => github.com/jperkin/apiserver v0.0.0-20240219180422-2d63424797e0
