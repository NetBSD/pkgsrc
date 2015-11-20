$NetBSD: patch-dom_events_MessageEvent.h,v 1.1 2015/11/20 14:48:21 joerg Exp $

--- dom/events/MessageEvent.h.orig	2015-11-19 13:56:48.000000000 +0000
+++ dom/events/MessageEvent.h
@@ -15,9 +15,6 @@ namespace mozilla {
 namespace dom {
 
 struct MessageEventInit;
-class MessagePort;
-class MessagePortBase;
-class MessagePortList;
 class OwningWindowProxyOrMessagePort;
 
 /**
