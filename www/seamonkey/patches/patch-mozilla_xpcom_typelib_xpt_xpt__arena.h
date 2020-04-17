$NetBSD: patch-mozilla_xpcom_typelib_xpt_xpt__arena.h,v 1.1 2020/04/17 00:18:24 joerg Exp $

--- mozilla/xpcom/typelib/xpt/xpt_arena.h.orig	2019-05-06 17:31:09.000000000 +0000
+++ mozilla/xpcom/typelib/xpt/xpt_arena.h
@@ -10,7 +10,7 @@
 #ifndef __xpt_arena_h__
 #define __xpt_arena_h__
 
-#include <stdlib.h>
+#include <cstdlib>
 #include "mozilla/Attributes.h"
 #include "mozilla/MemoryReporting.h"
 #include <stdint.h>
