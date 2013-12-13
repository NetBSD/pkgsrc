$NetBSD: patch-qttools_src_assistant_3rdparty_clucene_src_CLucene_util_Arrays.h,v 1.1 2013/12/13 14:38:35 ryoon Exp $

--- qttools/src/assistant/3rdparty/clucene/src/CLucene/util/Arrays.h.orig	2013-11-27 01:01:52.000000000 +0000
+++ qttools/src/assistant/3rdparty/clucene/src/CLucene/util/Arrays.h
@@ -151,7 +151,7 @@ CL_NS_DEF(util)
 
 			_itr1 itr1 = val1->begin();
 			_itr2 itr2 = val2->begin();
-			while ( --size >= 0 ){
+			while ( size-- >= 0 ){
 				if ( !comp(*itr1,*itr2) )
 					return false;
 				itr1++;
