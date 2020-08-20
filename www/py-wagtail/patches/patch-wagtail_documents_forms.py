$NetBSD: patch-wagtail_documents_forms.py,v 1.1 2020/08/20 12:58:35 joerg Exp $

#6337

--- wagtail/documents/forms.py.orig	2020-08-18 20:47:57.396518448 +0000
+++ wagtail/documents/forms.py
@@ -32,6 +32,19 @@ def get_document_form(model):
         })
 
 
+def get_document_upload_form(model):
+    fields = ('title', 'collection', 'file')
+
+    return modelform_factory(
+        model,
+        form=BaseDocumentForm,
+        fields=fields,
+        widgets={
+            'tags': widgets.AdminTagWidget,
+            'file': forms.FileInput()
+        })
+
+
 def get_document_multi_form(model):
     fields = [field for field in model.admin_form_fields if field != 'file']
     if 'collection' not in fields:
