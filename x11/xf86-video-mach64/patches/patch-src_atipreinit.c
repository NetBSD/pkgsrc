$NetBSD: patch-src_atipreinit.c,v 1.1 2015/04/02 22:16:47 tnn Exp $

From 810572536e153ac9e4615a35e2ab99dc266806da Mon Sep 17 00:00:00 2001
From: Dave Airlie <airlied@redhat.com>
Date: Sat, 15 Nov 2014 11:29:54 +1000
Subject: mach64: fix build probably not required with pci access anyways


diff --git a/src/atipreinit.c b/src/atipreinit.c
index e3048d2..dbcd9fd 100644
--- src/atipreinit.c
+++ src/atipreinit.c
@@ -1079,12 +1079,14 @@ ATIPreInit
         }
     }
 
+#ifndef XSERVER_LIBPCIACCESS
     if (!xf86LinearVidMem())
     {
         xf86DrvMsg(pScreenInfo->scrnIndex, X_ERROR,
             "A linear aperture is not available.\n");
         goto bail;
     }
+#endif
 
     /*
      * Set colour weights.
