$NetBSD: patch-nouveau_private.h,v 1.1 2020/04/12 19:41:21 joerg Exp $

--- nouveau/private.h.orig	2020-04-03 13:19:12.748087044 +0000
+++ nouveau/private.h
@@ -10,7 +10,7 @@
 #include "nouveau.h"
 
 #ifdef DEBUG
-drm_private uint32_t nouveau_debug;
+extern drm_private uint32_t nouveau_debug;
 #define dbg_on(lvl) (nouveau_debug & (1 << lvl))
 #define dbg(lvl, fmt, args...) do {                                            \
 	if (dbg_on((lvl)))                                                     \
