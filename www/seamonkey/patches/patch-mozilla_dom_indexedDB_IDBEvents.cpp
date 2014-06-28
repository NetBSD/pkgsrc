$NetBSD: patch-mozilla_dom_indexedDB_IDBEvents.cpp,v 1.3 2014/06/28 22:51:38 joerg Exp $

--- mozilla/dom/indexedDB/IDBEvents.cpp.orig	2014-06-13 00:46:05.000000000 +0000
+++ mozilla/dom/indexedDB/IDBEvents.cpp
@@ -15,8 +15,6 @@
 USING_INDEXEDDB_NAMESPACE
 using namespace mozilla::dom;
 
-NS_DEFINE_STATIC_IID_ACCESSOR(IDBVersionChangeEvent, IDBVERSIONCHANGEEVENT_IID)
-
 namespace {
 
 class EventFiringRunnable : public nsRunnable
