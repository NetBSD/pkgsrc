$NetBSD: patch-dom_base_nsAttrName.h,v 1.1 2022/07/21 23:56:39 nia Exp $

cbindgen gets confused by NetBSD's types being macros too
https://mail-index.netbsd.org/tech-pkg/2018/10/25/msg020395.html

--- dom/base/nsAttrName.h.orig	2019-01-18 00:20:23.000000000 +0000
+++ dom/base/nsAttrName.h
@@ -16,6 +16,10 @@
 #include "mozilla/dom/NodeInfo.h"
 #include "nsAtom.h"
 #include "nsDOMString.h"
+#ifdef __NetBSD__
+/* This is also a macro which causes problems with cbindgen */
+#undef uintptr_t
+#endif
 
 #define NS_ATTRNAME_NODEINFO_BIT 1
 class nsAttrName {
