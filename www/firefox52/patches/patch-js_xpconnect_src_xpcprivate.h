$NetBSD: patch-js_xpconnect_src_xpcprivate.h,v 1.1 2017/04/27 01:55:57 ryoon Exp $

From commit log 1.1:
  Instantiate WeakMapPtr explicitly to get the right visibility with
  clang.

--- js/xpconnect/src/xpcprivate.h.orig	2016-10-31 20:15:38.000000000 +0000
+++ js/xpconnect/src/xpcprivate.h
@@ -860,6 +860,8 @@ typedef nsTArray<InterpositionWhitelistP
 /***************************************************************************/
 // XPCWrappedNativeScope is one-to-one with a JS global object.
 
+extern template class JS_PUBLIC_API(JS::WeakMapPtr)<JSObject*, JSObject*>;
+
 class nsIAddonInterposition;
 class nsXPCComponentsBase;
 class XPCWrappedNativeScope final : public PRCList
