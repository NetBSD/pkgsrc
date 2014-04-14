$NetBSD: patch-LibYAML_yaml__private.h,v 1.1.2.2 2014/04/14 17:17:02 tron Exp $

* CVE-2014-2525
  https://bitbucket.org/xi/libyaml/commits/bce8b60f0b9af69fa9fab3093d0a41ba243de048

--- LibYAML/yaml_private.h.orig	2013-03-12 17:58:04.000000000 +0000
+++ LibYAML/yaml_private.h
@@ -132,9 +132,12 @@ yaml_string_join(
      (string).start = (string).pointer = (string).end = 0)
 
 #define STRING_EXTEND(context,string)                                           \
-    (((string).pointer+5 < (string).end)                                        \
+    ((((string).pointer+5 < (string).end)                                       \
         || yaml_string_extend(&(string).start,                                  \
-            &(string).pointer, &(string).end))
+            &(string).pointer, &(string).end)) ?                                \
+         1 :                                                                    \
+        ((context)->error = YAML_MEMORY_ERROR,                                  \
+         0))
 
 #define CLEAR(context,string)                                                   \
     ((string).pointer = (string).start,                                         \
