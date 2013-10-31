$NetBSD: patch-src_radeon__dri.c,v 1.1 2013/10/31 00:07:24 wiz Exp $

--- src/radeon_dri.c.orig	2012-06-25 08:19:41.000000000 +0000
+++ src/radeon_dri.c
@@ -40,6 +40,8 @@
 
 #include <string.h>
 #include <stdio.h>
+#include <sys/types.h>
+#include <sys/mman.h>
 
 				/* Driver data structures */
 #include "radeon.h"
@@ -1056,9 +1058,8 @@ static Bool RADEONDRIPciInit(RADEONInfoP
 	return FALSE;
     }
     xf86DrvMsg(pScreen->myNum, X_INFO,
-	       "[pci] %d kB allocated with handle 0x%08x\n",
-	       info->dri->gartSize*1024,
-	       (unsigned int)info->dri->pciMemHandle);
+	       "[pci] %d kB allocated with handle 0x%08lx\n",
+	       info->dri->gartSize*1024, info->dri->pciMemHandle);
 
     RADEONDRIInitGARTValues(info);
 
@@ -1069,12 +1070,11 @@ static Bool RADEONDRIPciInit(RADEONInfoP
 	return FALSE;
     }
     xf86DrvMsg(pScreen->myNum, X_INFO,
-	       "[pci] ring handle = 0x%08x\n",
-	       (unsigned int)info->dri->ringHandle);
+	       "[pci] ring handle = 0x%08lx, size = 0x%08lx\n", info->dri->ringHandle, info->dri->ringMapSize);
 
-    if (drmMap(info->dri->drmFD, info->dri->ringHandle, info->dri->ringMapSize,
-	       &info->dri->ring) < 0) {
-	xf86DrvMsg(pScreen->myNum, X_ERROR, "[pci] Could not map ring\n");
+    if ((ret = drmMap(info->dri->drmFD, info->dri->ringHandle, info->dri->ringMapSize,
+	       &info->dri->ring)) < 0) {
+	xf86DrvMsg(pScreen->myNum, X_ERROR, "[pci] Could not map ring: ret %d\n", ret);
 	return FALSE;
     }
     xf86DrvMsg(pScreen->myNum, X_INFO,
@@ -1091,8 +1091,8 @@ static Bool RADEONDRIPciInit(RADEONInfoP
 	return FALSE;
     }
     xf86DrvMsg(pScreen->myNum, X_INFO,
- 	       "[pci] ring read ptr handle = 0x%08x\n",
-	       (unsigned int)info->dri->ringReadPtrHandle);
+ 	       "[pci] ring read ptr handle = 0x%08lx\n",
+	       info->dri->ringReadPtrHandle);
 
     if (drmMap(info->dri->drmFD, info->dri->ringReadPtrHandle, info->dri->ringReadMapSize,
 	       &info->dri->ringReadPtr) < 0) {
@@ -1114,8 +1114,8 @@ static Bool RADEONDRIPciInit(RADEONInfoP
 	return FALSE;
     }
     xf86DrvMsg(pScreen->myNum, X_INFO,
- 	       "[pci] vertex/indirect buffers handle = 0x%08x\n",
-	       (unsigned int)info->dri->bufHandle);
+ 	       "[pci] vertex/indirect buffers handle = 0x%08lx\n",
+	       info->dri->bufHandle);
 
     if (drmMap(info->dri->drmFD, info->dri->bufHandle, info->dri->bufMapSize,
 	       &info->dri->buf) < 0) {
@@ -1137,8 +1137,8 @@ static Bool RADEONDRIPciInit(RADEONInfoP
 	return FALSE;
     }
     xf86DrvMsg(pScreen->myNum, X_INFO,
- 	       "[pci] GART texture map handle = 0x%08x\n",
-	       (unsigned int)info->dri->gartTexHandle);
+ 	       "[pci] GART texture map handle = 0x%08lx\n",
+	       info->dri->gartTexHandle);
 
     if (drmMap(info->dri->drmFD, info->dri->gartTexHandle, info->dri->gartTexMapSize,
 	       &info->dri->gartTex) < 0) {
@@ -1165,8 +1165,7 @@ static Bool RADEONDRIMapInit(RADEONInfoP
 	return FALSE;
     }
     xf86DrvMsg(pScreen->myNum, X_INFO,
-	       "[drm] register handle = 0x%08x\n",
-	       (unsigned int)info->dri->registerHandle);
+	       "[drm] register handle = 0x%08lx\n", info->dri->registerHandle);
 
     return TRUE;
 }
