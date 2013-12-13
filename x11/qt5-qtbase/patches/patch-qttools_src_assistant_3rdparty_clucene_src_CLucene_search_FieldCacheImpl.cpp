$NetBSD: patch-qttools_src_assistant_3rdparty_clucene_src_CLucene_search_FieldCacheImpl.cpp,v 1.1 2013/12/13 14:38:35 ryoon Exp $

--- qttools/src/assistant/3rdparty/clucene/src/CLucene/search/FieldCacheImpl.cpp.orig	2013-11-27 01:01:52.000000000 +0000
+++ qttools/src/assistant/3rdparty/clucene/src/CLucene/search/FieldCacheImpl.cpp
@@ -414,7 +414,7 @@ FieldCacheImpl::FileEntry::FileEntry (co
 	  _CLDECDELETE(term);
 
       try {
-        Term* term = enumerator->term(false);
+        term = enumerator->term(false);
         if (term == NULL) {
           _CLTHROWA(CL_ERR_Runtime,"no terms in field - cannot determine sort type"); //todo: make rich error: " + field + " 
         }
