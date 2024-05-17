$NetBSD: patch-listen__unix__setopt.go,v 1.1 2024/05/17 11:38:37 jperkin Exp $

https://github.com/caddyserver/caddy/pull/6021

--- listen_unix_setopt.go.orig	2024-05-17 11:31:03.073654054 +0000
+++ listen_unix_setopt.go
@@ -1,4 +1,4 @@
-//go:build unix && !freebsd
+//go:build unix && !freebsd && !solaris && !illumos
 
 package caddy
 
