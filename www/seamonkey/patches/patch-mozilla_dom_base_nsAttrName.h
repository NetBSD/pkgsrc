$NetBSD: patch-mozilla_dom_base_nsAttrName.h,v 1.2 2021/02/08 12:26:20 ryoon Exp $

--- dom/base/nsAttrName.h.orig	2020-02-17 23:37:48.000000000 +0000
+++ dom/base/nsAttrName.h
@@ -16,6 +16,10 @@
 #include "mozilla/dom/NodeInfo.h"
 #include "nsIAtom.h"
 #include "nsDOMString.h"
+#ifdef __NetBSD__
+/* This is also a macro which causes problems with cbindgen */
+#undef uintptr_t
+#endif
 
 #define NS_ATTRNAME_NODEINFO_BIT 1
 class nsAttrName
