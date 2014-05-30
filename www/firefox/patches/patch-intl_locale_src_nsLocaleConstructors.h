$NetBSD: patch-intl_locale_src_nsLocaleConstructors.h,v 1.1 2014/05/30 03:03:36 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- intl/locale/src/nsLocaleConstructors.h.orig	2014-05-06 22:55:40.000000000 +0000
+++ intl/locale/src/nsLocaleConstructors.h
@@ -16,11 +16,11 @@
 #include "nsPlatformCharset.h"
 #include "nsLocaleCID.h"
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
 #define USE_MAC_LOCALE
 #endif
 
-#if defined(XP_UNIX) && !defined(XP_MACOSX)
+#if defined(XP_UNIX) && !defined(MOZ_WIDGET_COCOA)
 #define USE_UNIX_LOCALE
 #endif
 
