$NetBSD: patch-cmd_traffic__cop_traffic__cop.cc,v 1.1 2020/05/14 18:59:48 joerg Exp $

--- cmd/traffic_cop/traffic_cop.cc.orig	2020-05-14 00:20:56.306834880 +0000
+++ cmd/traffic_cop/traffic_cop.cc
@@ -1861,7 +1861,7 @@ main(int /* argc */, const char *argv[])
   }
 
   setsid(); // Important, thanks Vlad. :)
-#if (defined(freebsd) && !defined(kfreebsd)) || defined(openbsd)
+#if (defined(freebsd) && !defined(kfreebsd)) || defined(openbsd) || defined(netbsd)
   setpgrp(0, 0);
 #else
   setpgrp();
