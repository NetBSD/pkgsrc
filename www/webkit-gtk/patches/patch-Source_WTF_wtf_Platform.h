$NetBSD: patch-Source_WTF_wtf_Platform.h,v 1.15 2024/11/14 22:13:52 wiz Exp $

From 63f7badbada070ebaadd318b2801818ecf7e7ea0 Mon Sep 17 00:00:00 2001
From: Don Olmstead <don.olmstead@sony.com>
Date: Sat, 26 Oct 2024 08:27:01 -0700
Subject: [PATCH] Support ICU 76.1 build

--- Source/WTF/wtf/Platform.h.orig	2024-11-14 21:17:56.889226979 +0000
+++ Source/WTF/wtf/Platform.h
@@ -115,6 +115,7 @@
 /* ICU configuration. Some of these match ICU defaults on some platforms, but we would like them consistently set everywhere we build WebKit. */
 #define U_HIDE_DEPRECATED_API 1
 #define U_SHOW_CPLUSPLUS_API 0
+#define U_SHOW_CPLUSPLUS_HEADER_API 0
 #ifdef __cplusplus
 #define UCHAR_TYPE char16_t
 #endif
