$NetBSD: patch-mozilla_browser_confvars.sh,v 1.1 2012/03/10 03:26:05 ryoon Exp $

--- mozilla/browser/confvars.sh.orig	2012-02-16 14:08:39.000000000 +0000
+++ mozilla/browser/confvars.sh
@@ -49,5 +49,5 @@ MOZ_EXTENSIONS_DEFAULT=" gnomevfs"
 # MOZ_APP_DISPLAYNAME will be set by branding/configure.sh
 # Changing either of these values requires a clobber to ensure correct results,
 # because branding dependencies are broken.
-MOZ_BRANDING_DIRECTORY=browser/branding/official
+MOZ_BRANDING_DIRECTORY=browser/branding/aurora
 MOZ_OFFICIAL_BRANDING_DIRECTORY=browser/branding/official
