$NetBSD: patch-xmlif_xmlif.l,v 1.1 2024/06/18 09:19:14 markd Exp $

via Fedora
commit 1375e2df75530cd198bd16ac3de38e2b0d126276
Author: Thomas Kuehne <thomas@kuehne.cn>
Date:   Sat Dec 11 21:10:41 2021 +0100

    fix -Wimplicit-int for ifsense
    
    fixes:
    xmlif/xmlif.l:46:8: warning: type defaults to ‘int’ in declaration of ‘ifsense’ [-Wimplicit-int]
       46 | static ifsense;                 /* sense of last `if' or unless seen */
          |        ^~~~~~~
    
    Signed-off-by: Thomas Kuehne <thomas@kuehne.cn>

commit 8e34f087bf410bcc5fe445933d6ad9bae54f24b5
Author: Thomas Kuehne <thomas@kuehne.cn>
Date:   Sat Dec 11 21:54:50 2021 +0100

    Fix return type of main function
    
    Fixes:
    xmlif/xmlif.l:242:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
      242 | main(int argc, char *argv[])
          | ^~~~
    
    Signed-off-by: Thomas Kuehne <thomas@kuehne.cn>

diff --git a/xmlif/xmlif.l b/xmlif/xmlif.l
index ac421367d47a2cd4..6e5970e147be21b1 100644
--- xmlif/xmlif.l
+++ xmlif/xmlif.l
@@ -43,7 +43,7 @@
 
 static char **selections;	/* selection tokens */
 static int nselections;		/* number of selections */
-static ifsense;			/* sense of last `if' or unless seen */
+static int ifsense;		/* sense of last `if' or unless seen */
 static char *attribute;		/* last attribute scanned */
 
 struct stack_t {
@@ -239,7 +239,7 @@ WS		[ \t\n]*
 
 int yywrap() {exit(0);};
 
-main(int argc, char *argv[])
+int main(int argc, char *argv[])
 {
     int i;
 
@@ -265,7 +265,7 @@ main(int argc, char *argv[])
 	    exit(1);
 	}
 
-    yylex();
+    return yylex();
 }
 
 /*
