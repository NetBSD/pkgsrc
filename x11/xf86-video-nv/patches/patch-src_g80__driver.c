$NetBSD: patch-src_g80__driver.c,v 1.1 2015/04/02 22:16:47 tnn Exp $

From fc78fe98222b0204b8a2872a529763d6fe5048da Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Tue, 25 Sep 2012 08:54:49 -0400
Subject: Remove mibstore.h

Signed-off-by: Adam Jackson <ajax@redhat.com>

diff --git a/src/g80_driver.c b/src/g80_driver.c
index cc4e197..719b96c 100644
--- src/g80_driver.c.orig	2012-07-17 06:47:02.000000000 +0000
+++ src/g80_driver.c
@@ -34,7 +34,6 @@
 #include <xf86Resources.h>
 #endif
 #include <mipointer.h>
-#include <mibstore.h>
 #include <micmap.h>
 #include <xf86cmap.h>
 #include <fb.h>
@@ -833,7 +832,6 @@ G80ScreenInit(SCREEN_INIT_ARGS_DECL)
         }
     }
 
-    miInitializeBackingStore(pScreen);
     xf86SetBackingStore(pScreen);
     xf86SetSilkenMouse(pScreen);
 
