$NetBSD: patch-ext_config.h,v 1.1 2021/02/14 15:06:43 taca Exp $

* Do not typedef bool unconditionally.

--- ext/config.h.orig	2021-01-11 06:26:19.797199031 +0000
+++ ext/config.h
@@ -17,8 +17,10 @@ extern "C" {
 #endif
 
 #ifndef __cplusplus
+#ifndef bool
 typedef unsigned int        bool;
 #endif
+#endif
 typedef unsigned char       frt_uchar;
 
 typedef posh_u16_t frt_u16;
