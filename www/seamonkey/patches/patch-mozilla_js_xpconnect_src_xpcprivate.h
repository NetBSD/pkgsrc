$NetBSD: patch-mozilla_js_xpconnect_src_xpcprivate.h,v 1.1 2014/11/17 19:08:07 joerg Exp $

--- mozilla/js/xpconnect/src/xpcprivate.h.orig	2014-10-14 06:36:24.000000000 +0000
+++ mozilla/js/xpconnect/src/xpcprivate.h
@@ -1006,6 +1006,11 @@ static inline bool IS_PROTO_CLASS(const 
 /***************************************************************************/
 // XPCWrappedNativeScope is one-to-one with a JS global object.
 
+#if __cplusplus >= 201103
+extern
+#endif
+template class JS_PUBLIC_API(JS::WeakMapPtr)<JSObject*, JSObject*>;
+
 class nsIAddonInterposition;
 class nsXPCComponentsBase;
 class XPCWrappedNativeScope : public PRCList
