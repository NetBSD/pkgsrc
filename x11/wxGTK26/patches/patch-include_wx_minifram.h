$NetBSD: patch-include_wx_minifram.h,v 1.1 2015/02/20 23:37:51 joerg Exp $

--- include/wx/minifram.h.orig	2015-02-20 22:51:24.000000000 +0000
+++ include/wx/minifram.h
@@ -10,7 +10,7 @@
 /////////////////////////////////////////////////////////////////////////////
 
 #ifndef _WX_MINIFRAM_H_BASE_
-#define _WX_MINIFRAMH_BASE_
+#define _WX_MINIFRAM_H_BASE_
 
 #if defined(__WXPALMOS__)
 #include "wx/palmos/minifram.h"
