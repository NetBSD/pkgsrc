$NetBSD: patch-mozilla_toolkit_modules_GMPUtils.jsm,v 1.3 2017/01/01 16:14:08 ryoon Exp $

--- mozilla/toolkit/modules/GMPUtils.jsm.orig	2016-12-14 02:09:56.000000000 +0000
+++ mozilla/toolkit/modules/GMPUtils.jsm
@@ -92,6 +92,7 @@ this.GMPUtils = {
       // Mac OSX, and Linux.
       return AppConstants.isPlatformAndVersionAtLeast("win", "6") ||
              AppConstants.platform == "macosx" ||
+             AppConstants.platform == "netbsd" ||
              AppConstants.platform == "linux";
     }
 
