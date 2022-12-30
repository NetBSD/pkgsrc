$NetBSD: patch-Source_JavaScriptCore_jsc.cpp,v 1.1 2022/12/30 20:19:10 adam Exp $

Remove ambiguity on Darwin.

--- Source/JavaScriptCore/jsc.cpp.orig	2022-12-30 08:36:58.000000000 +0000
+++ Source/JavaScriptCore/jsc.cpp
@@ -189,7 +189,7 @@ private:
 
 class ElementHandleOwner : public WeakHandleOwner {
 public:
-    bool isReachableFromOpaqueRoots(Handle<JSC::Unknown> handle, void*, SlotVisitor& visitor) override
+    bool isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown> handle, void*, SlotVisitor& visitor) override
     {
         Element* element = jsCast<Element*>(handle.slot()->asCell());
         return visitor.containsOpaqueRoot(element->root());
