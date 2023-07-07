$NetBSD: patch-dtools_xtmDbTools.c,v 1.2 2023/07/07 12:45:25 nia Exp $

Avoid int to pointer conversion warnings.
Add a mode to open() call with O_CREAT.

--- dtools/xtmDbTools.c.orig	1997-05-04 22:27:52.000000000 +0000
+++ dtools/xtmDbTools.c
@@ -47,6 +47,8 @@ static char SCCSID[] = "@(#) Module: xtm
 
 #include <fcntl.h>
 #include <stdio.h>
+#include <stdint.h>
+#include <stdlib.h>
 #include <unistd.h>
 #include <ctype.h>
 #include <sys/stat.h>
@@ -1813,7 +1815,7 @@ XTM_DB_STATUS
 
     /* Insert the date in the sorted list. */
     lst_status = LstLinkSearchFirst( *list_ref, 
-                                     (void *) record.date,
+                                     (void *)(uintptr_t)record.date,
                                      (EQUALS_FUNC_TYPE) dateSortFunc );
 
     if( lst_status == LST_OK )
@@ -1896,7 +1898,7 @@ XTM_DB_STATUS
           case XTM_DB_DAY_NOTE:
             lst_status = LstLinkSearchFirst( 
                            *note_list_ref, 
-                           (void *) entry_record.entry.time_stamp,
+                           (void *)(uintptr_t)entry_record.entry.time_stamp,
                            (EQUALS_FUNC_TYPE) entryIdSortFunc );
 
             if( lst_status == LST_OK )
@@ -1910,7 +1912,7 @@ XTM_DB_STATUS
           case XTM_DB_DAY_ENTRY:
             lst_status = LstLinkSearchFirst( 
                            *entry_list_ref, 
-                           (void *) entry_record.entry.time_stamp,
+                           (void *)(uintptr_t)entry_record.entry.time_stamp,
                            (EQUALS_FUNC_TYPE) entryTimeSortFunc );
 
             if( lst_status == LST_OK )
@@ -1984,7 +1986,7 @@ XTM_DB_STATUS
         case XTM_DB_DAY_NOTE:
           lst_status = LstLinkSearchFirst( 
                          *note_list_ref, 
-                         (void *) entry_record.entry.time_stamp,
+                         (void *)(uintptr_t)entry_record.entry.time_stamp,
                          (EQUALS_FUNC_TYPE) entryIdSortFunc );
 
           if( lst_status == LST_OK )
@@ -1998,7 +2000,7 @@ XTM_DB_STATUS
         case XTM_DB_DAY_ENTRY:
           lst_status = LstLinkSearchFirst( 
                          *entry_list_ref, 
-                         (void *) entry_record.entry.time_stamp,
+                         (void *)(uintptr_t)entry_record.entry.time_stamp,
                          (EQUALS_FUNC_TYPE) entryTimeSortFunc );
 
           if( lst_status == LST_OK )
@@ -2072,7 +2074,7 @@ XTM_DB_STATUS
       case XTM_DB_DAY_NOTE:
         lst_status = LstLinkSearchFirst( 
                        *note_list_ref, 
-                       (void *) entry_record.entry.time_stamp,
+                       (void *)(uintptr_t)entry_record.entry.time_stamp,
                        (EQUALS_FUNC_TYPE) entryIdSortFunc );
 
         if( lst_status == LST_OK )
@@ -2086,7 +2088,7 @@ XTM_DB_STATUS
       case XTM_DB_DAY_ENTRY:
         lst_status = LstLinkSearchFirst( 
                        *entry_list_ref, 
-                       (void *) entry_record.entry.time_stamp,
+                       (void *)(uintptr_t)entry_record.entry.time_stamp,
                        (EQUALS_FUNC_TYPE) entryTimeSortFunc );
 
         if( lst_status == LST_OK )
@@ -2332,7 +2334,7 @@ XTM_DB_STATUS
   sprintf( filename, "%s/%s_%s_%d",
            message_dir, XTM_DB_MESSAGE_FILE, msg_info -> from, new_id );
 
-  file_ref = open( filename, (O_CREAT | O_RDWR) );
+  file_ref = open( filename, (O_CREAT | O_RDWR, 0600) );
   if( file_ref == -1 )
     raise exception;
 
