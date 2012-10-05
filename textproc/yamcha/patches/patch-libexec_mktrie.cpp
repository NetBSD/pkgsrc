$NetBSD: patch-libexec_mktrie.cpp,v 1.1.2.2 2012/10/05 13:22:23 tron Exp $

1) Fix segfault bug - bad char cast
2) There is a duplicate delete; "is" was previously freed already.

--- libexec/mktrie.cpp.orig	2004-09-20 09:59:16.000000000 +0000
+++ libexec/mktrie.cpp
@@ -111,13 +111,16 @@ int main (int argc, char **argv)
     column.clear();
     tokenize<std::string> ((const char*)buf, std::back_inserter(column));
     if (column.empty()) continue;
-    unsigned int *tmp = new unsigned int [column.size()-1];
-    for (unsigned int i = 0; i < (column.size()-1); i++) 
-       tmp[i] = atoi (column[i+1].c_str());
+    string tmp;
+    for (unsigned int i = 0; i < (column.size()-1); i++) {
+        char hexbuf[10]; // assume string(UINT32_MAX).size -> 9
+        snprintf(hexbuf, sizeof(hexbuf), "%09x", atoi (column[i+1].c_str()));
+        tmp = tmp + hexbuf;
+    }
     feature f;
-    f.f = (unsigned char *)tmp; // cast
+    f.f = (unsigned char *)strdup(tmp.c_str());
     f.id = atoi (column[0].c_str());
-    f.len = 4*(column.size()-1);
+    f.len = tmp.size();
     fv.push_back (f);
   }
   
@@ -145,6 +148,4 @@ int main (int argc, char **argv)
     std::cerr << "FATAL: cannot save " << argv[2] << std::endl;
     return -1;
   }
-
-  if (file != "-") delete is;
 }
