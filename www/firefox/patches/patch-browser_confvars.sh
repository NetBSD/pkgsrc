$NetBSD: patch-browser_confvars.sh,v 1.2 2017/08/10 14:46:15 ryoon Exp $

--- browser/confvars.sh.orig	2017-07-31 16:20:48.000000000 +0000
+++ browser/confvars.sh
@@ -30,6 +30,7 @@ if test "$OS_ARCH" = "WINNT"; then
   fi
 fi
 
+MOZ_RUST_MP4PARSE=1
 if test "$NIGHTLY_BUILD"; then
   MOZ_RUST_URLPARSE=1
 fi
