$NetBSD: patch-go.mod,v 1.8 2024/02/20 12:43:19 jperkin Exp $

Bluge upstream is dead, and k8s refuse to support non-Linux platforms, so we're
stuck carrying these changes.  Previous pull requests:

  https://github.com/blugelabs/bluge/pull/139
  https://github.com/kubernetes/kubernetes/pull/120498

go get github.com/jperkin/bluge@master
go mod edit --replace=github.com/blugelabs/bluge=github.com/jperkin/bluge@<version output>
go get github.com/jperkin/apiserver@master
go mod edit --replace=k8s.io/apiserver=github.com/jperkin/apiserver@<version output>
go mod tidy

--- go.mod.orig	2024-02-02 15:14:58.000000000 +0000
+++ go.mod
@@ -121,7 +121,7 @@ require (
 	gopkg.in/mail.v2 v2.3.1 // @grafana/backend-platform
 	gopkg.in/yaml.v2 v2.4.0 // indirect
 	gopkg.in/yaml.v3 v3.0.1 // @grafana/alerting-squad-backend
-	xorm.io/builder v0.3.6 // @grafana/backend-platform
+	xorm.io/builder v0.3.6 // indirect; @grafana/backend-platform
 	xorm.io/core v0.7.3 // @grafana/backend-platform
 	xorm.io/xorm v0.8.2 // @grafana/alerting-squad-backend
 )
@@ -173,7 +173,7 @@ require (
 	github.com/grpc-ecosystem/go-grpc-prometheus v1.2.1-0.20191002090509-6af20e3a5340 // indirect
 	github.com/hashicorp/errwrap v1.1.0 // indirect
 	github.com/hashicorp/go-msgpack v0.5.5 // indirect
-	github.com/hashicorp/go-multierror v1.1.1 // @grafana/alerting-squad
+	github.com/hashicorp/go-multierror v1.1.1 // indirect; @grafana/alerting-squad
 	github.com/hashicorp/go-sockaddr v1.0.2 // indirect
 	github.com/hashicorp/golang-lru v0.6.0 // indirect
 	github.com/hashicorp/yamux v0.1.1 // indirect
@@ -477,6 +477,8 @@ require (
 	github.com/matttproud/golang_protobuf_extensions/v2 v2.0.0 // indirect
 )
 
+require github.com/blugelabs/ice/v2 v2.0.1 // indirect
+
 // Use fork of crewjam/saml with fixes for some issues until changes get merged into upstream
 replace github.com/crewjam/saml => github.com/grafana/saml v0.4.15-0.20231025143828-a6c0e9b86a4c
 
@@ -497,3 +499,7 @@ replace xorm.io/xorm => ./pkg/util/xorm
 replace github.com/prometheus/alertmanager => github.com/grafana/prometheus-alertmanager v0.25.1-0.20231027171310-70c52bf65758
 
 exclude github.com/mattn/go-sqlite3 v2.0.3+incompatible
+
+replace github.com/blugelabs/bluge v0.1.9 => github.com/jperkin/bluge v0.0.0-20221115155924-ffd91b43c395
+
+replace k8s.io/apiserver v0.29.0 => github.com/jperkin/apiserver v0.0.0-20240219180422-2d63424797e0
