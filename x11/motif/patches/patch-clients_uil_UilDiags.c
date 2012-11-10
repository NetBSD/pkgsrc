$NetBSD: patch-clients_uil_UilDiags.c,v 1.1 2012/11/10 17:10:10 ryoon Exp $

--- clients/uil/UilDiags.c.orig	2012-10-22 14:50:39.000000000 +0000
+++ clients/uil/UilDiags.c
@@ -304,13 +304,13 @@ void	diag_issue_diagnostic
 	    */
 
 #ifndef NO_MESSAGE_CATALOG
-	    sprintf( loc_buffer,
+	    snprintf( loc_buffer, sizeof(loc_buffer),
 		     catgets(uil_catd, UIL_SET_MISC,
 			     UIL_MISC_0, "\t\t line: %d  file: %s"),
 		     az_src_rec->w_line_number,
 		     src_get_file_name( az_src_rec ) );
 #else
-	    sprintf( loc_buffer,
+	    snprintf( loc_buffer, sizeof(loc_buffer),
 		     "\t\t line: %d  file: %s",
 		     az_src_rec->w_line_number,
 		     src_get_file_name( az_src_rec ) );
@@ -358,7 +358,7 @@ void	diag_issue_diagnostic
 
 	    if (l_start_column != diag_k_no_column)
 #ifndef NO_MESSAGE_CATALOG
-	      sprintf(loc_buffer,
+	      snprintf(loc_buffer, sizeof(loc_buffer),
 		      catgets(uil_catd, UIL_SET_MISC,
 			      UIL_MISC_1, 
 			      "\t\t line: %d  position: %d  file: %s"),
@@ -366,7 +366,7 @@ void	diag_issue_diagnostic
 		      l_start_column + 1,
 		      src_get_file_name( az_src_rec ) );
 #else
-	      sprintf(loc_buffer,
+	      snprintf(loc_buffer, sizeof(loc_buffer),
 		      "\t\t line: %d  position: %d  file: %s",
 		      az_src_rec->w_line_number,
 		      l_start_column + 1,
@@ -374,13 +374,14 @@ void	diag_issue_diagnostic
 #endif
 	    else
 #ifndef NO_MESSAGE_CATALOG
-		sprintf( loc_buffer, catgets(uil_catd, UIL_SET_MISC,
+		snprintf( loc_buffer, sizeof(loc_buffer),
+			 catgets(uil_catd, UIL_SET_MISC,
 					     UIL_MISC_0,
 					     "\t\t line: %d  file: %s"),
 			 az_src_rec->w_line_number,
 			 src_get_file_name( az_src_rec ) );
 #else
-		sprintf( loc_buffer,
+		snprintf( loc_buffer, sizeof(loc_buffer),
 			 "\t\t line: %d  file: %s",
 			 az_src_rec->w_line_number,
 			 src_get_file_name( az_src_rec ) );
