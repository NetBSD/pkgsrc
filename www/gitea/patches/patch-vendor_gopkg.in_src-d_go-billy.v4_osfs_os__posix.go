$NetBSD: patch-vendor_gopkg.in_src-d_go-billy.v4_osfs_os__posix.go,v 1.1 2019/03/24 21:34:23 nia Exp $

--- vendor/gopkg.in/src-d/go-billy.v4/osfs/os_posix.go.orig	2019-02-11 23:54:21.666290102 +0000
+++ vendor/gopkg.in/src-d/go-billy.v4/osfs/os_posix.go
@@ -3,19 +3,19 @@
 package osfs
 
 import (
-	"syscall"
+	"golang.org/x/sys/unix"
 )
 
 func (f *file) Lock() error {
 	f.m.Lock()
 	defer f.m.Unlock()
 
-	return syscall.Flock(int(f.File.Fd()), syscall.LOCK_EX)
+	return unix.Flock(int(f.File.Fd()), unix.LOCK_EX)
 }
 
 func (f *file) Unlock() error {
 	f.m.Lock()
 	defer f.m.Unlock()
 
-	return syscall.Flock(int(f.File.Fd()), syscall.LOCK_UN)
+	return unix.Flock(int(f.File.Fd()), unix.LOCK_UN)
 }
