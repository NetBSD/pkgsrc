$NetBSD: patch-go.mod,v 1.1 2022/04/18 18:28:07 bsiegert Exp $

Update quic-go to a version that builds on Go 1.18.

--- go.mod.orig	2022-04-18 13:14:51.852692985 +0000
+++ go.mod
@@ -13,7 +13,8 @@ require (
 	github.com/google/uuid v1.3.0
 	github.com/klauspost/compress v1.13.6
 	github.com/klauspost/cpuid/v2 v2.0.9
-	github.com/lucas-clemente/quic-go v0.23.0
+	github.com/lucas-clemente/quic-go v0.27.0
+	github.com/marten-seemann/qtls-go1-15 v0.1.4 // indirect
 	github.com/mholt/acmez v1.0.1
 	github.com/naoina/go-stringutil v0.1.0 // indirect
 	github.com/naoina/toml v0.1.1
