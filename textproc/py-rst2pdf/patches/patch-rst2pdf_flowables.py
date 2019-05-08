$NetBSD: patch-rst2pdf_flowables.py,v 1.1 2019/05/08 10:20:16 adam Exp $

Add missing import.

--- rst2pdf/flowables.py.orig	2019-05-08 09:52:12.000000000 +0000
+++ rst2pdf/flowables.py
@@ -12,7 +12,7 @@ import re
 from reportlab.platypus import *
 from reportlab.platypus.doctemplate import *
 from reportlab.lib.enums import *
-
+import reportlab
 
 from reportlab.lib.units import *
 from reportlab.lib.enums import TA_LEFT, TA_CENTER, TA_RIGHT
