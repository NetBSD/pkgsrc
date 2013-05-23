$NetBSD: patch-markupsafe_____init____.py,v 1.1 2013/05/23 15:08:26 joerg Exp $

--- markupsafe/__init__.py.orig	2013-05-23 10:39:34.000000000 +0000
+++ markupsafe/__init__.py
@@ -65,7 +65,7 @@ class Markup(text_type):
     """
     __slots__ = ()
 
-    def __new__(cls, base=u'', encoding=None, errors='strict'):
+    def __new__(cls, base='', encoding=None, errors='strict'):
         if hasattr(base, '__html__'):
             base = base.__html__()
         if encoding is None:
@@ -139,7 +139,7 @@ class Markup(text_type):
                     return unichr(int(name[1:]))
             except ValueError:
                 pass
-            return u''
+            return ''
         return _entity_re.sub(handle_match, text_type(self))
 
     def striptags(self):
@@ -150,7 +150,7 @@ class Markup(text_type):
         >>> Markup("Main &raquo;  <em>About</em>").striptags()
         u'Main \xbb About'
         """
-        stripped = u' '.join(_striptags_re.sub('', self).split())
+        stripped = ' '.join(_striptags_re.sub('', self).split())
         return Markup(stripped).unescape()
 
     @classmethod
