$NetBSD: patch-mozilla_dom_indexedDB_IDBEvents.h,v 1.1 2014/05/18 21:28:28 joerg Exp $

--- mozilla/dom/indexedDB/IDBEvents.h.orig	2014-05-17 22:33:14.000000000 +0000
+++ mozilla/dom/indexedDB/IDBEvents.h
@@ -158,6 +158,8 @@ protected:
   uint64_t mNewVersion;
 };
 
+NS_DEFINE_STATIC_IID_ACCESSOR(IDBVersionChangeEvent, IDBVERSIONCHANGEEVENT_IID)
+
 END_INDEXEDDB_NAMESPACE
 
 #endif // mozilla_dom_indexeddb_idbevents_h__
