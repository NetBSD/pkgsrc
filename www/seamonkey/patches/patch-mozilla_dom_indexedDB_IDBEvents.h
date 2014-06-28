$NetBSD: patch-mozilla_dom_indexedDB_IDBEvents.h,v 1.3 2014/06/28 22:51:38 joerg Exp $

--- mozilla/dom/indexedDB/IDBEvents.h.orig	2014-06-13 00:46:05.000000000 +0000
+++ mozilla/dom/indexedDB/IDBEvents.h
@@ -158,6 +158,8 @@ protected:
   uint64_t mNewVersion;
 };
 
+NS_DEFINE_STATIC_IID_ACCESSOR(IDBVersionChangeEvent, IDBVERSIONCHANGEEVENT_IID)
+
 END_INDEXEDDB_NAMESPACE
 
 #endif // mozilla_dom_indexeddb_idbevents_h__
