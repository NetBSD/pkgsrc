$NetBSD: patch-js_xpconnect_src_xpcprivate.h,v 1.4 2017/08/10 14:46:15 ryoon Exp $

From commit log 1.1:
  Instantiate WeakMapPtr explicitly to get the right visibility with
  clang.

--- js/xpconnect/src/xpcprivate.h.orig	2017-07-31 16:20:47.000000000 +0000
+++ js/xpconnect/src/xpcprivate.h
@@ -884,6 +884,8 @@ typedef nsTArray<InterpositionWhitelistP
 /***************************************************************************/
 // XPCWrappedNativeScope is one-to-one with a JS global object.
 
+extern template class JS_PUBLIC_API(JS::WeakMapPtr)<JSObject*, JSObject*>;
+
 class nsIAddonInterposition;
 class nsXPCComponentsBase;
 class XPCWrappedNativeScope final
