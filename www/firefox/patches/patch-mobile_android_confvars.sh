$NetBSD: patch-mobile_android_confvars.sh,v 1.1 2017/06/14 11:28:44 ryoon Exp $

--- mobile/android/confvars.sh.orig	2017-06-05 20:45:15.000000000 +0000
+++ mobile/android/confvars.sh
@@ -30,6 +30,8 @@ MOZ_XULRUNNER=
 MOZ_CAPTURE=1
 MOZ_RAW=1
 
+MOZ_RUST_MP4PARSE=1
+
 # use custom widget for html:select
 MOZ_USE_NATIVE_POPUP_WINDOWS=1
 
