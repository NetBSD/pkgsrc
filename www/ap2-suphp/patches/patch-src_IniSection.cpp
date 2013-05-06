$NetBSD: patch-src_IniSection.cpp,v 1.1 2013/05/06 15:02:13 joerg Exp $

--- src/IniSection.cpp.orig	2013-05-04 14:22:11.000000000 +0000
+++ src/IniSection.cpp
@@ -36,8 +36,8 @@ void suPHP::IniSection::putValue(const s
 const std::vector<std::string> suPHP::IniSection::getValues(const std::string& key) const
     throw (KeyNotFoundException) {
     std::vector<std::string> values;
-    std::pair<std::multimap<const std::string, const std::string>::const_iterator, std::multimap<const std::string, const std::string>::const_iterator> range = this->entries.equal_range(key);
-    for (std::multimap<const std::string, const std::string>::const_iterator pos = 
+    std::pair<std::multimap<std::string, std::string>::const_iterator, std::multimap<std::string, std::string>::const_iterator> range = this->entries.equal_range(key);
+    for (std::multimap<std::string, std::string>::const_iterator pos = 
         range.first; pos != range.second; pos++) {
         values.push_back(pos->second);
     }
@@ -62,7 +62,7 @@ std::string suPHP::IniSection::getValue(
 
 const std::vector<std::string> suPHP::IniSection::getKeys() const {
     std::vector<std::string> keys;
-    for (std::multimap<const std::string, const std::string>::const_iterator pos =
+    for (std::multimap<std::string, std::string>::const_iterator pos =
              this->entries.begin();
          pos != this->entries.end(); pos++) {
         keys.push_back(pos->first);
