$NetBSD: patch-vendor_github.com_edsrzf_mmap-go_msync__netbsd.go,v 1.1 2019/03/24 21:34:23 nia Exp $

--- vendor/github.com/edsrzf/mmap-go/msync_netbsd.go.orig	2019-02-12 11:18:50.418527745 +0000
+++ vendor/github.com/edsrzf/mmap-go/msync_netbsd.go
@@ -4,5 +4,3 @@
 
 package mmap
 
-const _SYS_MSYNC = 277
-const _MS_SYNC = 0x04
