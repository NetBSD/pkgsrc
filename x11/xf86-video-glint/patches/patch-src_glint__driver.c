$NetBSD: patch-src_glint__driver.c,v 1.1 2015/04/02 22:16:46 tnn Exp $

From 073d5b0b392781bf4a6aa7f9e2dbe2ae51caed2c Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Tue, 25 Sep 2012 08:54:38 -0400
Subject: Remove mibstore.h

Signed-off-by: Adam Jackson <ajax@redhat.com>

diff --git a/src/glint_driver.c b/src/glint_driver.c
index b6d20a9..aa78516 100644
--- src/glint_driver.c
+++ src/glint_driver.c
@@ -52,8 +52,6 @@
 #include "compiler.h"
 #include "mipointer.h"
 
-#include "mibstore.h"
-
 #include "pm3_regs.h"
 #include "glint_regs.h"
 #include "IBM.h"
@@ -2904,7 +2902,6 @@ GLINTScreenInit(SCREEN_INIT_ARGS_DECL)
         }
     }
 
-    miInitializeBackingStore(pScreen);
     xf86SetBackingStore(pScreen);
     xf86SetSilkenMouse(pScreen);
