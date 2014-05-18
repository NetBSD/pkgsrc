$NetBSD: patch-mozilla_dom_indexedDB_IDBEvents.cpp,v 1.1 2014/05/18 21:28:28 joerg Exp $

--- mozilla/dom/indexedDB/IDBEvents.cpp.orig	2014-05-17 22:33:17.000000000 +0000
+++ mozilla/dom/indexedDB/IDBEvents.cpp
@@ -15,8 +15,6 @@
 USING_INDEXEDDB_NAMESPACE
 using namespace mozilla::dom;
 
-NS_DEFINE_STATIC_IID_ACCESSOR(IDBVersionChangeEvent, IDBVERSIONCHANGEEVENT_IID)
-
 namespace {
 
 class EventFiringRunnable : public nsRunnable
