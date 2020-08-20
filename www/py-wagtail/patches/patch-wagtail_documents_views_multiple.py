$NetBSD: patch-wagtail_documents_views_multiple.py,v 1.1 2020/08/20 12:58:35 joerg Exp $

#6337

--- wagtail/documents/views/multiple.py.orig	2020-08-11 09:43:49.000000000 +0000
+++ wagtail/documents/views/multiple.py
@@ -12,7 +12,7 @@ from wagtail.core.models import Collecti
 from wagtail.search.backends import get_search_backends
 
 from .. import get_document_model
-from ..forms import get_document_form, get_document_multi_form
+from ..forms import get_document_form, get_document_upload_form, get_document_multi_form
 from ..permissions import permission_policy
 
 permission_checker = PermissionPolicyChecker(permission_policy)
@@ -23,6 +23,7 @@ permission_checker = PermissionPolicyChe
 def add(request):
     Document = get_document_model()
     DocumentForm = get_document_form(Document)
+    DocumentUploadForm = get_document_upload_form(Document)
     DocumentMultiForm = get_document_multi_form(Document)
 
     collections = permission_policy.collections_user_has_permission_for(request.user, 'add')
@@ -40,7 +41,7 @@ def add(request):
             return HttpResponseBadRequest("Must upload a file")
 
         # Build a form for validation
-        form = DocumentForm({
+        form = DocumentUploadForm({
             'title': request.FILES['files[]'].name,
             'collection': request.POST.get('collection'),
         }, {
