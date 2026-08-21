$NetBSD: patch-.._k8s.io_apiserver_pkg_server_options_serving__noportreuse.go,v 1.1 2026/08/21 18:04:06 tnn Exp $

unix.SO_REUSEPORT unavailable on SunOS.

--- ../k8s.io/apiserver/pkg/server/options/serving_noportreuse.go.orig	2026-08-19 21:36:50.861707135 +0000
+++ ../k8s.io/apiserver/pkg/server/options/serving_noportreuse.go
@@ -0,0 +1,41 @@
+//go:build illumos
+
+/*
+Copyright 2020 The Kubernetes Authors.
+
+Licensed under the Apache License, Version 2.0 (the "License");
+you may not use this file except in compliance with the License.
+You may obtain a copy of the License at
+
+    http://www.apache.org/licenses/LICENSE-2.0
+
+Unless required by applicable law or agreed to in writing, software
+distributed under the License is distributed on an "AS IS" BASIS,
+WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
+See the License for the specific language governing permissions and
+limitations under the License.
+*/
+
+package options
+
+import (
+	"fmt"
+
+	"syscall"
+
+	"golang.org/x/sys/unix"
+
+	"k8s.io/klog/v2"
+)
+
+func permitPortReuse(network, addr string, conn syscall.RawConn) error {
+	return fmt.Errorf("port reuse is not supported")
+}
+
+func permitAddressReuse(network, addr string, conn syscall.RawConn) error {
+	return conn.Control(func(fd uintptr) {
+		if err := syscall.SetsockoptInt(int(fd), syscall.SOL_SOCKET, unix.SO_REUSEADDR, 1); err != nil {
+			klog.Warningf("failed to set SO_REUSEADDR on socket: %v", err)
+		}
+	})
+}
