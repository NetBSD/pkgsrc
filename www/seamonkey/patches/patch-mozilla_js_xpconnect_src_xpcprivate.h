$NetBSD: patch-mozilla_js_xpconnect_src_xpcprivate.h,v 1.2 2015/02/15 02:11:03 ryoon Exp $

--- mozilla/js/xpconnect/src/xpcprivate.h.orig	2015-02-05 04:39:06.000000000 +0000
+++ mozilla/js/xpconnect/src/xpcprivate.h
@@ -1016,6 +1016,8 @@ static inline bool IS_PROTO_CLASS(const 
 /***************************************************************************/
 // XPCWrappedNativeScope is one-to-one with a JS global object.
 
+extern template class JS_PUBLIC_API(JS::WeakMapPtr)<JSObject*, JSObject*>;
+
 class nsIAddonInterposition;
 class nsXPCComponentsBase;
 class XPCWrappedNativeScope : public PRCList
