$NetBSD: patch-tools_System.c,v 1.1 2023/01/22 20:08:17 vins Exp $

Avoid int to pointer conversion warnings.

--- tools/System.c.orig	1997-05-07 20:15:47.000000000 +0000
+++ tools/System.c
@@ -102,8 +102,8 @@ void
     if( line_no > 0 ) 
       printf( "%s: (%d), ", file_name, line_no );
 
-    printf( "SysBaseCalloc(), ref: %d, ref_count: %d\n", 
-            (int) ref, memory_ref_count );
+    printf( "SysBaseCalloc(), ref: %p, ref_count: %d\n", 
+            ref, memory_ref_count );
 
     memory_ref_count++;
   }
@@ -133,8 +133,8 @@ void
     if( line_no > 0 ) 
       printf( "%s: (%d), ", file_name, line_no );
 
-    printf( "SysBaseFree(), ref: %d, ref_count: %d\n",
-            (int) pointer, memory_ref_count );
+    printf( "SysBaseFree(), ref: %p, ref_count: %d\n",
+            pointer, memory_ref_count );
 
     memory_ref_count++;
   }
@@ -166,8 +166,8 @@ void
     if( line_no > 0 ) 
       printf( "%s: (%d), ", file_name, line_no );
 
-    printf( "SysBaseMalloc(), ref: %d, ref_count: %d\n", 
-            (int) ref, memory_ref_count );
+    printf( "SysBaseMalloc(), ref: %p, ref_count: %d\n", 
+            ref, memory_ref_count );
 
     memory_ref_count++;
   }
@@ -208,8 +208,8 @@ extern void
     if( line_no > 0 ) 
       printf( "%s: (%d), ", file_name, line_no );
 
-    printf( "SysBaseRealloc(), ref: %d, ref_count: %d\n", 
-            (int) ref, memory_ref_count );
+    printf( "SysBaseRealloc(), ref: %p, ref_count: %d\n", 
+            ref, memory_ref_count );
 
     memory_ref_count++;
   }
