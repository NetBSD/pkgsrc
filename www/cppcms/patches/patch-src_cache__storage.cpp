$NetBSD: patch-src_cache__storage.cpp,v 1.1 2020/05/22 01:17:25 joerg Exp $

--- src/cache_storage.cpp.orig	2020-05-21 23:28:18.301370981 +0000
+++ src/cache_storage.cpp
@@ -25,13 +25,13 @@
 #endif
 
 #include <map>
+#include <unordered_map>
 #include <list>
 #include <limits>
 #include <time.h>
 #include <cppcms/cstdint.h>
 
 
-#include <cppcms_boost/unordered/unordered_map.hpp>
 namespace boost = cppcms_boost;
 
 namespace cppcms {
@@ -137,10 +137,10 @@ class mem_cache : public base_cache {
 
 	typedef std::basic_string<char,std::char_traits<char>,allocator > string_type;
 
-	typedef boost::unordered_map<
+	typedef std::unordered_map<
 			string_type,
 			container,
-			boost::hash<string_type>,
+			std::hash<string_type>,
 			std::equal_to<string_type>,
 			typename allocator::template rebind<std::pair<const string_type,container> >::other
 		> map_type;
