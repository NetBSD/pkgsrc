$NetBSD: patch-toolkit_modules_GMPUtils.jsm,v 1.3 2016/09/20 20:01:41 ryoon Exp $

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
 
