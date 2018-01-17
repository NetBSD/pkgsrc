$NetBSD: patch-sipgen_gencode.c,v 1.1 2018/01/17 19:16:05 markd Exp $

Fixed the handling of the default value of unscoped enums when using
old compilers.  [dd017d3e1454] [tip]

--- sipgen/gencode.c	2017-11-06 13:45:14.000000000 +1300
+++ sipgen/gencode.c	2017-11-11 15:30:06.000000000 +1300
@@ -305,6 +305,7 @@
 static int isString(argDef *ad);
 static scopedNameDef *stripScope(scopedNameDef *snd, classDef *ecd,
         StripAction strip);
+static void prEnumMemberScope(enumMemberDef *emd, FILE *fp);
 
 
 /*
@@ -3295,25 +3296,14 @@
 
         if (!isNoScope(emd->ed))
         {
-            classDef *ecd = emd->ed->ecd;
-
             if (isScopedEnum(emd->ed))
-            {
-                prcode(fp, "::%s::", emd->ed->cname->text);
-            }
-            else if (ecd != NULL)
-            {
-                if (isProtectedEnum(emd->ed))
-                    prcode(fp, "sip%C::", classFQCName(ecd));
-                else if (isProtectedClass(ecd))
-                    prcode(fp, "%U::", ecd);
-                else
-                    prcode(fp, "%S::", classFQCName(ecd));
-            }
+                prcode(fp, "::%s", emd->ed->cname->text);
+            else if (emd->ed->ecd != NULL)
+                prEnumMemberScope(emd, fp);
             else if (mtd != NULL)
-            {
-                prcode(fp, "%S::", mtd->iff->fqcname);
-            }
+                prcode(fp, "%S", mtd->iff->fqcname);
+
+            prcode(fp, "::");
         }
 
         prcode(fp, "%s%s, %d},\n", emd->cname, (generating_c ? "" : ")"), emd->ed->first_alt->enumnr);
@@ -7592,7 +7582,13 @@
 
         if (ed->members != NULL)
         {
-            prcode(fp, "%E::%s", ed, ed->members->cname);
+            if (isScopedEnum(ed))
+                prcode(fp, "%E", ed);
+            else
+                prEnumMemberScope(ed->members, fp);
+
+            prcode(fp, "::%s", ed->members->cname);
+
             return;
         }
 
@@ -15531,3 +15527,19 @@
 
     return snd;
 }
+
+
+/*
+ * Generate the scope of a member of an unscoped enum.
+ */
+static void prEnumMemberScope(enumMemberDef *emd, FILE *fp)
+{
+    classDef *ecd = emd->ed->ecd;
+
+    if (isProtectedEnum(emd->ed))
+        prcode(fp, "sip%C", classFQCName(ecd));
+    else if (isProtectedClass(ecd))
+        prcode(fp, "%U", ecd);
+    else
+        prcode(fp, "%S", classFQCName(ecd));
+}
