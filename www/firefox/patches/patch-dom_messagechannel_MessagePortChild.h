$NetBSD: patch-dom_messagechannel_MessagePortChild.h,v 1.1 2017/08/16 14:13:44 ryoon Exp $

defined symbols for architecture x86_64 "vtable for mozilla::dom::MessagePortChild"

https://bugzilla.mozilla.org/show_bug.cgi?id=1382863

Bug 1382863 Part 1: Move MessagePortChild constructor out of inline, creating a vtable needed for clang compilation.

Already committed for Firefox 56.

--- dom/messagechannel/MessagePortChild.h.orig	2017-06-15 20:52:23.000000000 +0000
+++ dom/messagechannel/MessagePortChild.h
@@ -19,7 +19,7 @@ class MessagePortChild final : public PM
 public:
   NS_INLINE_DECL_REFCOUNTING(MessagePortChild)
 
-  MessagePortChild() : mPort(nullptr) {}
+  MessagePortChild();
 
   void SetPort(MessagePort* aPort)
   {
