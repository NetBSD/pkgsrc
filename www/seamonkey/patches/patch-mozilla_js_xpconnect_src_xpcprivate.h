$NetBSD: patch-mozilla_js_xpconnect_src_xpcprivate.h,v 1.3 2017/08/18 23:55:07 ryoon Exp $

--- mozilla/js/xpconnect/src/xpcprivate.h.orig	2017-07-07 05:36:59.000000000 +0000
+++ mozilla/js/xpconnect/src/xpcprivate.h
@@ -842,6 +842,8 @@ typedef nsTArray<InterpositionWhitelistP
 /***************************************************************************/
 // XPCWrappedNativeScope is one-to-one with a JS global object.
 
+extern template class JS_PUBLIC_API(JS::WeakMapPtr)<JSObject*, JSObject*>;
+
 class nsIAddonInterposition;
 class nsXPCComponentsBase;
 class XPCWrappedNativeScope final : public PRCList
