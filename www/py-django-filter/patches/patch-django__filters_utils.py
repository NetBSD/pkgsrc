$NetBSD: patch-django__filters_utils.py,v 1.1 2020/10/11 23:48:18 joerg Exp $

Support newer Django versions.

--- django_filters/utils.py.orig	2020-10-11 20:39:52.623467617 +0000
+++ django_filters/utils.py
@@ -3,11 +3,10 @@ from collections import OrderedDict
 
 import django
 from django.conf import settings
-from django.core.exceptions import FieldError
+from django.core.exceptions import FieldError, FieldDoesNotExist
 from django.db import models
 from django.db.models.constants import LOOKUP_SEP
 from django.db.models.expressions import Expression
-from django.db.models.fields import FieldDoesNotExist
 from django.db.models.fields.related import ForeignObjectRel, RelatedField
 from django.utils import timezone
 from django.utils.encoding import force_str
