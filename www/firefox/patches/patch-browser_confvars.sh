$NetBSD: patch-browser_confvars.sh,v 1.1 2017/06/14 11:28:44 ryoon Exp $

--- browser/confvars.sh.orig	2017-06-05 20:45:14.000000000 +0000
+++ browser/confvars.sh
@@ -30,6 +30,7 @@ if test "$OS_ARCH" = "WINNT"; then
   fi
 fi
 
+MOZ_RUST_MP4PARSE=1
 if test "$NIGHTLY_BUILD"; then
   MOZ_RUST_URLPARSE=1
 fi
