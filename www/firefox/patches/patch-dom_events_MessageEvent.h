$NetBSD: patch-dom_events_MessageEvent.h,v 1.1 2015/11/20 14:48:20 joerg Exp $

--- dom/events/MessageEvent.h.orig	2015-10-29 22:17:54.000000000 +0000
+++ dom/events/MessageEvent.h
@@ -16,9 +16,6 @@ namespace mozilla {
 namespace dom {
 
 struct MessageEventInit;
-class MessagePort;
-class MessagePortBase;
-class MessagePortList;
 class OwningWindowProxyOrMessagePortOrClient;
 
 namespace workers {
