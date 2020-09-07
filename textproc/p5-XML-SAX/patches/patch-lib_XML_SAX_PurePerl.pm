$NetBSD: patch-lib_XML_SAX_PurePerl.pm,v 1.1 2020/09/07 17:21:34 wiz Exp $

--- lib/XML/SAX/PurePerl.pm.orig	2019-06-14 01:57:58.000000000 +0000
+++ lib/XML/SAX/PurePerl.pm
@@ -308,21 +308,27 @@ sub CDSect {
     
     $self->start_cdata({});
     
-    $data = $reader->data;
+    my $chars;
     while (1) {
-        $self->parser_error("EOF looking for CDATA section end", $reader)
-            unless length($data);
+        # do not miss "]]>", so try to read at least 3 chars
+        $data = $reader->data(3);
+        $self->parser_error
+                ("EOF looking for CDATA section end", $reader)
+                unless length($data) >= 3;
         
         if ($data =~ /^(.*?)\]\]>/s) {
-            my $chars = $1;
+            $chars = $1;
             $reader->move_along(length($chars) + 3);
             $self->characters({Data => $chars});
             last;
         }
         else {
-            $self->characters({Data => $data});
-            $reader->move_along(length($data));
-            $data = $reader->data;
+            # the last one or two "]" could be the beginning of a "]]>",
+            # so do no eat them
+            $data =~ /^(.*?)\]{0,2}+$/s;
+            $chars = $1;
+            $reader->move_along(length($chars));
+            $self->characters({Data => $chars});
         }
     }
     $self->end_cdata({});
