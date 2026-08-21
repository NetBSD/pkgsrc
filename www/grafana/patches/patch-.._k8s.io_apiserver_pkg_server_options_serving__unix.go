$NetBSD: patch-.._k8s.io_apiserver_pkg_server_options_serving__unix.go,v 1.1 2026/08/21 18:04:06 tnn Exp $

unix.SO_REUSEPORT unavailable on SunOS.

--- ../k8s.io/apiserver/pkg/server/options/serving_unix.go.orig	2026-08-19 21:25:30.996190999 +0000
+++ ../k8s.io/apiserver/pkg/server/options/serving_unix.go
@@ -1,4 +1,4 @@
-//go:build !windows
+//go:build !windows && !illumos
 
 /*
 Copyright 2020 The Kubernetes Authors.
