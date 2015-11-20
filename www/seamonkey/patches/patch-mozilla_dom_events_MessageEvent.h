$NetBSD: patch-mozilla_dom_events_MessageEvent.h,v 1.1 2015/11/20 14:48:21 joerg Exp $

--- mozilla/dom/events/MessageEvent.h.orig	2015-09-25 07:36:28.000000000 +0000
+++ mozilla/dom/events/MessageEvent.h
@@ -16,9 +16,6 @@ namespace mozilla {
 namespace dom {
 
 struct MessageEventInit;
-class MessagePort;
-class MessagePortBase;
-class MessagePortList;
 class OwningWindowProxyOrMessagePortOrClient;
 
 namespace workers {
