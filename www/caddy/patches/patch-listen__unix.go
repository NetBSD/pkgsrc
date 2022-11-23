$NetBSD: patch-listen__unix.go,v 1.1 2022/11/23 10:07:30 jperkin Exp $

SunOS platforms do not have SO_REUSEPORT.

--- listen_unix.go.orig	2022-10-13 17:30:57.000000000 +0000
+++ listen_unix.go
@@ -15,7 +15,7 @@
 // TODO: Go 1.19 introduced the "unix" build tag. We have to support Go 1.18 until Go 1.20 is released.
 // When Go 1.19 is our minimum, remove this build tag, since "_unix" in the filename will do this.
 // (see also change needed in listen.go)
-//go:build aix || android || darwin || dragonfly || freebsd || hurd || illumos || ios || linux || netbsd || openbsd || solaris
+//go:build aix || android || darwin || dragonfly || freebsd || hurd || ios || linux || netbsd || openbsd
 
 package caddy
 
