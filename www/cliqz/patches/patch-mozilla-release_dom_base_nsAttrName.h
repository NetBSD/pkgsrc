$NetBSD: patch-mozilla-release_dom_base_nsAttrName.h,v 1.1 2019/04/19 14:02:03 fox Exp $

cbindgen gets confused by NetBSD's types being macros too
https://mail-index.netbsd.org/tech-pkg/2018/10/25/msg020395.html

Original patch from ryoon, imported from www/firefox

--- mozilla-release/dom/base/nsAttrName.h.orig	2018-11-16 08:40:07.000000000 +0000
+++ mozilla-release/dom/base/nsAttrName.h
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
