$NetBSD: patch-dom_messagechannel_MessagePort.cpp,v 1.1 2017/08/16 14:13:44 ryoon Exp $

Undefined symbols for architecture x86_64 "vtable for mozilla::dom::MessagePortChild"

https://bugzilla.mozilla.org/show_bug.cgi?id=1382863

Bug 1382863 Part 1: Move MessagePortChild constructor out of inline, creating a vtable needed for clang compilation.

Already committed for Firefox 56.

--- dom/messagechannel/MessagePort.cpp.orig	2017-07-31 16:20:53.000000000 +0000
+++ dom/messagechannel/MessagePort.cpp
@@ -47,6 +47,11 @@ using namespace mozilla::dom::workers;
 namespace mozilla {
 namespace dom {
 
+MessagePortChild::MessagePortChild()
+  : mPort(nullptr)
+{
+}
+
 class PostMessageRunnable final : public CancelableRunnable
 {
   friend class MessagePort;
