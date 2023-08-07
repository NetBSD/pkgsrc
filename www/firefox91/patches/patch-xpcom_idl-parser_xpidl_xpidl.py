$NetBSD: patch-xpcom_idl-parser_xpidl_xpidl.py,v 1.1 2023/08/07 13:28:04 abs Exp $

Update for modern (>3.9) python regex rules (taken from firefox-102)

--- xpcom/idl-parser/xpidl/xpidl.py.orig	2022-08-15 18:05:58.000000000 +0000
+++ xpcom/idl-parser/xpidl/xpidl.py
@@ -1563,13 +1563,13 @@ class IDLParser(object):
     t_ignore = " \t"
 
     def t_multilinecomment(self, t):
-        r"/\*(?s).*?\*/"
+        r"/\*(\n|.)*?\*/"
         t.lexer.lineno += t.value.count("\n")
         if t.value.startswith("/**"):
             self._doccomments.append(t.value)
 
     def t_singlelinecomment(self, t):
-        r"(?m)//.*?$"
+        r"//[^\n]*"
 
     def t_IID(self, t):
         return t
@@ -1582,7 +1582,7 @@ class IDLParser(object):
         return t
 
     def t_LCDATA(self, t):
-        r"(?s)%\{[ ]*C\+\+[ ]*\n(?P<cdata>.*?\n?)%\}[ ]*(C\+\+)?"
+        r"%\{[ ]*C\+\+[ ]*\n(?P<cdata>(\n|.)*?\n?)%\}[ ]*(C\+\+)?"
         t.type = "CDATA"
         t.value = t.lexer.lexmatch.group("cdata")
         t.lexer.lineno += t.value.count("\n")
