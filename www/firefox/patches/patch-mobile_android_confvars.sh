$NetBSD: patch-mobile_android_confvars.sh,v 1.2 2017/08/10 14:46:15 ryoon Exp $

--- mobile/android/confvars.sh.orig	2017-07-31 16:20:50.000000000 +0000
+++ mobile/android/confvars.sh
@@ -30,6 +30,8 @@ MOZ_XULRUNNER=
 MOZ_CAPTURE=1
 MOZ_RAW=1
 
+MOZ_RUST_MP4PARSE=1
+
 # use custom widget for html:select
 MOZ_USE_NATIVE_POPUP_WINDOWS=1
 
