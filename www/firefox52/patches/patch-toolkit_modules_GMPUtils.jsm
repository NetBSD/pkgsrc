$NetBSD: patch-toolkit_modules_GMPUtils.jsm,v 1.1 2017/04/27 01:55:57 ryoon Exp $

* Enable Google widevine CDM for NetBSD

--- toolkit/modules/GMPUtils.jsm.orig	2016-08-10 20:27:55.000000000 +0000
+++ toolkit/modules/GMPUtils.jsm
@@ -92,6 +92,7 @@ this.GMPUtils = {
       // Mac OSX, and Linux.
       return AppConstants.isPlatformAndVersionAtLeast("win", "6") ||
              AppConstants.platform == "macosx" ||
+             AppConstants.platform == "netbsd" ||
              AppConstants.platform == "linux";
     }
 
