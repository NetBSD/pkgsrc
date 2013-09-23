$NetBSD: patch-ext_appengine_fields.py,v 1.1 2013/09/23 20:36:27 kleink Exp $

--- wtforms/ext/appengine/fields.py.orig	2013-05-03 10:40:00.000000000 +0200
+++ wtforms/ext/appengine/fields.py	2013-09-23 22:26:20.000000000 +0200
@@ -114,7 +114,7 @@
 
     def __init__(self, label=None, validators=None, reference_class=None,
                  label_attr=None, get_label=None, allow_blank=False,
-                 blank_text=u'', **kwargs):
+                 blank_text='', **kwargs):
         super(KeyPropertyField, self).__init__(label, validators,
                                                      **kwargs)
         if label_attr is not None:
@@ -149,7 +149,7 @@
 
     def iter_choices(self):
         if self.allow_blank:
-            yield (u'__None', self.blank_text, self.data is None)
+            yield ('__None', self.blank_text, self.data is None)
 
         for obj in self.query:
             key = str(obj.key.id())
@@ -170,9 +170,9 @@
                 if self.data.key == obj.key:
                     break
             else:
-                raise ValueError(self.gettext(u'Not a valid choice'))
+                raise ValueError(self.gettext('Not a valid choice'))
         elif not self.allow_blank:
-            raise ValueError(self.gettext(u'Not a valid choice'))
+            raise ValueError(self.gettext('Not a valid choice'))
 
 
 class StringListPropertyField(fields.TextAreaField):
@@ -203,14 +203,14 @@
         if self.raw_data:
             return self.raw_data[0]
         else:
-            return self.data and unicode("\n".join(self.data)) or u''
+            return text_type('\n'.join(self.data)) if self.data else ''
 
     def process_formdata(self, valuelist):
         if valuelist:
             try:
                 self.data = [int(value) for value in valuelist[0].splitlines()]
             except ValueError:
-                raise ValueError(self.gettext(u'Not a valid integer list'))
+                raise ValueError(self.gettext('Not a valid integer list'))
 
 
 class GeoPtPropertyField(fields.TextField):
