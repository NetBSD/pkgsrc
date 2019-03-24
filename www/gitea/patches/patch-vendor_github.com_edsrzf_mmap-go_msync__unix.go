$NetBSD: patch-vendor_github.com_edsrzf_mmap-go_msync__unix.go,v 1.1 2019/03/24 21:34:23 nia Exp $

--- vendor/github.com/edsrzf/mmap-go/msync_unix.go.orig	2019-01-31 16:11:25.000000000 +0000
+++ vendor/github.com/edsrzf/mmap-go/msync_unix.go
@@ -2,13 +2,13 @@
 // Use of this source code is governed by a BSD-style
 // license that can be found in the LICENSE file.
 
-// +build darwin dragonfly freebsd linux openbsd solaris
+// +build darwin dragonfly freebsd linux openbsd !solaris
 
 package mmap
 
 import (
-	"syscall"
+	"golang.org/x/sys/unix"
 )
 
-const _SYS_MSYNC = syscall.SYS_MSYNC
-const _MS_SYNC = syscall.MS_SYNC
+const _SYS_MSYNC = unix.SYS_MSYNC
+const _MS_SYNC = unix.MS_SYNC
