$NetBSD: patch-dom_indexedDB_IDBEvents.cpp,v 1.3 2014/06/14 16:20:07 joerg Exp $

--- dom/indexedDB/IDBEvents.cpp.orig	2014-06-14 15:18:52.000000000 +0000
+++ dom/indexedDB/IDBEvents.cpp
@@ -15,8 +15,6 @@
 USING_INDEXEDDB_NAMESPACE
 using namespace mozilla::dom;
 
-NS_DEFINE_STATIC_IID_ACCESSOR(IDBVersionChangeEvent, IDBVERSIONCHANGEEVENT_IID)
-
 namespace {
 
 class EventFiringRunnable : public nsRunnable
