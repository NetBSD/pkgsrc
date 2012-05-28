$NetBSD: patch-LibYAML_perl__libyaml.c,v 1.1.2.2 2012/05/28 10:58:03 tron Exp $

fix for CVS-2012-1152 taken from
https://rt.cpan.org/Ticket/Attachment/920541/477607/YAML-LibYAML-0.35-format-error.patch

--- LibYAML/perl_libyaml.c.orig	2011-04-03 16:28:08.000000000 +0000
+++ LibYAML/perl_libyaml.c
@@ -188,7 +188,7 @@ Load(SV *yaml_sv)
     return;
 
 load_error:
-    croak(loader_error_msg(&loader, NULL));
+    croak("%s", loader_error_msg(&loader, NULL));
 }
 
 /*
@@ -271,7 +271,7 @@ load_node(perl_yaml_loader_t *loader)
     return return_sv;
 
     load_error:
-        croak(loader_error_msg(loader, NULL));
+        croak("%s", loader_error_msg(loader, NULL));
 }
 
 /*
@@ -314,7 +314,7 @@ load_mapping(perl_yaml_loader_t *loader,
         else if (strlen(tag) <= strlen(prefix) ||
             ! strnEQ(tag, prefix, strlen(prefix))
         ) croak(
-            loader_error_msg(loader, form("bad tag found for hash: '%s'", tag))
+            "%s", loader_error_msg(loader, form("bad tag found for hash: '%s'", tag))
         );
         class = tag + strlen(prefix);
         sv_bless(hash_ref, gv_stashpv(class, TRUE)); 
@@ -347,7 +347,7 @@ load_sequence(perl_yaml_loader_t *loader
         else if (strlen(tag) <= strlen(prefix) ||
             ! strnEQ(tag, prefix, strlen(prefix))
         ) croak(
-            loader_error_msg(loader, form("bad tag found for array: '%s'", tag))
+            "%s", loader_error_msg(loader, form("bad tag found for array: '%s'", tag))
         );
         class = tag + strlen(prefix);
         sv_bless(array_ref, gv_stashpv(class, TRUE)); 
