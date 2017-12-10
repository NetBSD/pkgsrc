$NetBSD: patch-toolkit_modules_GMPUtils.jsm,v 1.5 2017/12/10 00:45:09 ryoon Exp $

--- toolkit/modules/GMPUtils.jsm.orig	2017-09-14 20:16:01.000000000 +0000
+++ toolkit/modules/GMPUtils.jsm
@@ -74,7 +74,8 @@ this.GMPUtils = {
       // Mac OSX, and Linux.
       return AppConstants.isPlatformAndVersionAtLeast("win", "6") ||
              AppConstants.platform == "macosx" ||
-             AppConstants.platform == "linux";
+             AppConstants.platform == "linux" ||
+             AppConstants.platform == "netbsd";
     }
 
     return true;
