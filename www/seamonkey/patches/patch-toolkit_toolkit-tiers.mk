$NetBSD: patch-toolkit_toolkit-tiers.mk,v 1.3 2012/03/19 10:36:00 ryoon Exp $

--- mozilla/toolkit/toolkit-tiers.mk.orig	2012-03-13 05:33:17.000000000 +0000
+++ mozilla/toolkit/toolkit-tiers.mk
@@ -81,7 +81,7 @@ ifndef MOZ_NATIVE_BZ2
 tier_platform_dirs += modules/libbz2
 endif
 tier_platform_dirs += modules/libmar
-tier_platform_dirs += other-licenses/bsdiff
+#tier_platform_dirs += other-licenses/bsdiff
 endif
 
 tier_platform_dirs	+= gfx/qcms
