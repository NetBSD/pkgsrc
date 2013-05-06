$NetBSD: patch-src_IniSection.hpp,v 1.1 2013/05/06 15:02:14 joerg Exp $

--- src/IniSection.hpp.orig	2013-05-04 14:21:17.000000000 +0000
+++ src/IniSection.hpp
@@ -40,7 +40,7 @@ namespace suPHP {
      */
     class IniSection {
     private:
-        std::multimap<const std::string, const std::string> entries;
+        std::multimap<std::string, std::string> entries;
         void putValue(const std::string key, const std::string value);
         void removeValues(const std::string& key);
 
