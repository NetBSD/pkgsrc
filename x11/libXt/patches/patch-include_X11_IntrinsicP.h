$NetBSD: patch-include_X11_IntrinsicP.h,v 1.2 2023/05/26 05:09:20 wiz Exp $

Do not use _Static_assert in C++ code.
https://gitlab.freedesktop.org/xorg/lib/libxt/-/issues/17

--- include/X11/IntrinsicP.h.orig	2023-04-09 20:48:48.000000000 +0000
+++ include/X11/IntrinsicP.h
@@ -64,7 +64,7 @@ typedef struct {
     XtIntPtr	xrm_default_type; /* Default representation type quark	*/
     XtPointer	xrm_default_addr; /* Default resource address		*/
 } XrmResource, *XrmResourceList;
-#if __STDC_VERSION__ >= 201112L
+#if __STDC_VERSION__ >= 201112L && !defined(__cplusplus)
 _Static_assert(XtOffsetOf(XrmResource, xrm_default_addr) ==
                    XtOffsetOf(XtResource, default_addr),
                "Field offset mismatch");
