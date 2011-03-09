$NetBSD: patch-MoinMoin_parser_text__rst.py,v 1.1.2.2 2011/03/09 20:01:48 tron Exp $

Security fix: XSS issue in rst parser CVE-2011-1058
http://hg.moinmo.in/moin/1.9/rev/97208f67798f

--- MoinMoin/parser/text_rst.py.orig	2010-06-26 21:46:42.000000000 +0000
+++ MoinMoin/parser/text_rst.py
@@ -391,6 +391,9 @@ class MoinTranslator(html4css1.HTMLTrans
                 # for images with targets).
                 if not [i for i in node.children if i.__class__ == docutils.nodes.image]:
                     node['classes'].append('interwiki')
+	    elif prefix == 'javascript':
+		# is someone trying to do XSS with javascript?
+		node['refuri'] = 'javascript:alert("it does not work")'
             elif prefix != '':
                 # Some link scheme (http, file, https, mailto, etc.), add class
                 # information if the reference doesn't have a child image (don't
