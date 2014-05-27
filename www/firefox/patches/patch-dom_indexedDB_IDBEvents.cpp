$NetBSD: patch-dom_indexedDB_IDBEvents.cpp,v 1.1 2014/05/27 09:58:51 joerg Exp $

--- dom/indexedDB/IDBEvents.cpp.orig	2014-05-23 13:27:09.000000000 +0000
+++ dom/indexedDB/IDBEvents.cpp
@@ -15,8 +15,6 @@
 USING_INDEXEDDB_NAMESPACE
 using namespace mozilla::dom;
 
-NS_DEFINE_STATIC_IID_ACCESSOR(IDBVersionChangeEvent, IDBVERSIONCHANGEEVENT_IID)
-
 namespace {
 
 class EventFiringRunnable : public nsRunnable
