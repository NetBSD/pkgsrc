$NetBSD: patch-String.cpp,v 1.1 2013/07/11 14:05:14 sborrill Exp $

Fix build with 64-bit time_t
--- String.cpp.orig	2013-07-11 14:43:00.000000000 +0100
+++ String.cpp	2013-07-11 14:46:38.000000000 +0100
@@ -102,6 +102,27 @@
     }
 #endif
 
+#ifdef __GCCVER3
+    String::String(const long long num) {
+        std::ostringstream buf;
+        buf << num << std::ends;
+        std::string s = buf.str();
+        char* bs = (char*)s.c_str();
+        int l = strlen(bs);
+        data = new char[l + 1];
+        memcpy(data, bs, l);
+        sl = l;
+        data[sl] = '\0';
+    }
+#else
+    String::String(const long long num) {
+        std::ostrstream buf;
+        buf << num << std::ends;
+        data = buf.str();  // with side effect: it calls buf.freeze()
+        sl = buf.pcount() - 1;
+    }
+#endif
+
 String::String(const char* bs, int len) {
     data = new char[len + 1];
     memcpy(data, bs, len);
