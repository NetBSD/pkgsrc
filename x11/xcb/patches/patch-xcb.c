$NetBSD: patch-xcb.c,v 1.1 2025/09/19 06:24:25 mrg Exp $

Port to modern C.

--- xcb.c.orig	2002-11-25 07:28:17.000000000 -0800
+++ xcb.c	2025-09-18 23:20:23.386617678 -0700
@@ -1350,6 +1350,7 @@
     }
 }
 
+int
 main (argc, argv)
      int argc;
      char **argv;
