$NetBSD: patch-sphinx_util_nodes.py,v 1.1 2016/04/05 05:38:43 khorben Exp $

Fix classifiers containing regular expressions

--- sphinx/util/nodes.py.orig	2016-01-09 07:50:40.000000000 +0000
+++ sphinx/util/nodes.py
@@ -50,7 +50,7 @@ def apply_source_workaround(node):
         # strip classifier from rawsource of term
         for classifier in reversed(node.parent.traverse(nodes.classifier)):
             node.rawsource = re.sub(
-                '\s*:\s*%s' % classifier.astext(), '', node.rawsource)
+                '\s*:\s*%s' % re.escape(classifier.astext()), '', node.rawsource)
 
     # workaround: recommonmark-0.2.0 doesn't set rawsource attribute
     if not node.rawsource:
