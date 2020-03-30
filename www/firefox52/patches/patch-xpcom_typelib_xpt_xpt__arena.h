$NetBSD: patch-xpcom_typelib_xpt_xpt__arena.h,v 1.1 2020/03/30 19:46:02 joerg Exp $

--- xpcom/typelib/xpt/xpt_arena.h.orig	2020-03-29 17:32:32.848757813 +0000
+++ xpcom/typelib/xpt/xpt_arena.h
@@ -10,7 +10,7 @@
 #ifndef __xpt_arena_h__
 #define __xpt_arena_h__
 
-#include <stdlib.h>
+#include <cstdlib>
 #include "mozilla/Attributes.h"
 #include "mozilla/MemoryReporting.h"
 #include <stdint.h>
