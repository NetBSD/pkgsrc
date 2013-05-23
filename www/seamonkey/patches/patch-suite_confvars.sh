$NetBSD: patch-suite_confvars.sh,v 1.1 2013/05/23 13:25:30 ryoon Exp $

--- suite/confvars.sh.orig	2013-05-03 03:02:30.000000000 +0000
+++ suite/confvars.sh
@@ -38,7 +38,7 @@ MOZ_SERVICES_SYNC=1
 MOZ_URL_CLASSIFIER=1
 # Disable WebRTC as we don't use it currently and to work around bug 837618
 # for Mac
-if test "$OS_ARCH" == "Darwin"; then
+if test "$OS_ARCH" = "Darwin"; then
 MOZ_WEBRTC=
 fi
 
