$NetBSD: patch-dom_indexedDB_IDBEvents.h,v 1.3 2014/06/14 16:20:07 joerg Exp $

--- dom/indexedDB/IDBEvents.h.orig	2014-06-14 15:18:50.000000000 +0000
+++ dom/indexedDB/IDBEvents.h
@@ -158,6 +158,8 @@ protected:
   uint64_t mNewVersion;
 };
 
+NS_DEFINE_STATIC_IID_ACCESSOR(IDBVersionChangeEvent, IDBVERSIONCHANGEEVENT_IID)
+
 END_INDEXEDDB_NAMESPACE
 
 #endif // mozilla_dom_indexeddb_idbevents_h__
