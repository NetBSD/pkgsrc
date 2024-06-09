$NetBSD: patch-go.mod,v 1.10 2024/06/09 22:44:05 wiz Exp $

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

--- go.mod.orig	2024-05-13 07:34:53.000000000 +0000
+++ go.mod
@@ -474,6 +474,7 @@ require github.com/grafana/authlib v0.0.
 
 require (
 	github.com/bahlo/generic-list-go v0.2.0 // indirect
+	github.com/blugelabs/ice/v2 v2.0.1 // indirect
 	github.com/buger/jsonparser v1.1.1 // indirect
 	github.com/bytedance/sonic v1.9.1 // indirect
 	github.com/chenzhuoyu/base64x v0.0.0-20221115062448-fe3a3abad311 // indirect
@@ -519,3 +520,7 @@ exclude github.com/mattn/go-sqlite3 v2.0
 
 // Use our fork xorm. go.work currently overrides this and points to the local ./pkg/util/xorm directory.
 replace xorm.io/xorm => github.com/grafana/grafana/pkg/util/xorm v0.0.1
+
+replace github.com/blugelabs/bluge => github.com/jperkin/bluge v0.0.0-20221115155924-ffd91b43c395
+
+replace k8s.io/apiserver => github.com/jperkin/apiserver v0.0.0-20240219180422-2d63424797e0
