$NetBSD: patch-listen__unix.go,v 1.3 2024/05/17 11:38:37 jperkin Exp $

https://github.com/caddyserver/caddy/pull/6021

--- listen_unix.go.orig	2024-05-17 11:30:39.511852361 +0000
+++ listen_unix.go
@@ -15,7 +15,7 @@
 // Even though the filename ends in _unix.go, we still have to specify the
 // build constraint here, because the filename convention only works for
 // literal GOOS values, and "unix" is a shortcut unique to build tags.
-//go:build unix
+//go:build unix && !solaris && !illumos
 
 package caddy
 
