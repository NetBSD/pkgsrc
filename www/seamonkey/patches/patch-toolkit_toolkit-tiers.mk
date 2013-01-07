$NetBSD: patch-toolkit_toolkit-tiers.mk,v 1.7 2013/01/07 21:55:30 ryoon Exp $

--- mozilla/toolkit/toolkit-tiers.mk.orig	2012-11-18 10:19:53.000000000 +0000
+++ mozilla/toolkit/toolkit-tiers.mk
@@ -43,7 +43,7 @@ ifdef MOZ_UPDATER
 ifndef MOZ_NATIVE_BZ2
 tier_platform_dirs += modules/libbz2
 endif
-tier_platform_dirs += other-licenses/bsdiff
+#tier_platform_dirs += other-licenses/bsdiff
 endif
 
 tier_platform_dirs	+= gfx/qcms
