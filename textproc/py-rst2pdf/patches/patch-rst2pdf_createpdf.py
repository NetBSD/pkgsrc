$NetBSD: patch-rst2pdf_createpdf.py,v 1.1 2019/05/08 10:20:16 adam Exp $

Add missing import.

--- rst2pdf/createpdf.py.orig	2019-05-08 10:08:54.000000000 +0000
+++ rst2pdf/createpdf.py
@@ -76,6 +76,7 @@ try:
 except ImportError:
     from docutils.utils.roman import toRoman
 
+import reportlab
 from reportlab.platypus import *
 from reportlab.platypus.doctemplate import IndexingFlowable
 from reportlab.platypus.flowables import _listWrapOn, _Container
