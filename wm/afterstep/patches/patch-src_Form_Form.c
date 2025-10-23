$NetBSD: patch-src_Form_Form.c,v 1.1 2025/10/23 01:28:08 gutteridge Exp $

Use ctype.h correctly.

--- src/Form/Form.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/Form/Form.c
@@ -377,7 +377,7 @@ ParseOptions (char *file_name)
   while (fgets (line_buf, sizeof (line_buf), fp))
     {
       cp = line_buf;
-      while (isspace (*cp))
+      while (isspace ((unsigned char)*cp))
 	cp++;			/* skip blanks */
       if (*cp != '*')
 	continue;
@@ -398,12 +398,12 @@ ParseOptions (char *file_name)
 	{
 	  cp += 8;
 	  geom = 1;
-	  while (isspace (*cp))
+	  while (isspace ((unsigned char)*cp))
 	    cp++;
 	  gx = atoi (cp);
-	  while (!isspace (*cp))
+	  while (!isspace ((unsigned char)*cp))
 	    cp++;
-	  while (isspace (*cp))
+	  while (isspace ((unsigned char)*cp))
 	    cp++;
 	  gy = atoi (cp);
 	  fprintf (fp_err, "Position @ (%d, %d)\n", gx, gy);
@@ -412,7 +412,7 @@ ParseOptions (char *file_name)
       else if (strncmp (cp, "Fore", 4) == 0)
 	{
 	  cp += 4;
-	  while (isspace (*cp))
+	  while (isspace ((unsigned char)*cp))
 	    cp++;
 	  color_names[c_fore] = copystring (cp, 0);
 	  fprintf (fp_err, "ColorFore: %s\n", color_names[c_fore]);
@@ -421,7 +421,7 @@ ParseOptions (char *file_name)
       else if (strncmp (cp, "Back", 4) == 0)
 	{
 	  cp += 4;
-	  while (isspace (*cp))
+	  while (isspace ((unsigned char)*cp))
 	    cp++;
 	  color_names[c_back] = copystring (cp, 0);
 	  fprintf (fp_err, "ColorBack: %s\n", color_names[c_back]);
@@ -430,7 +430,7 @@ ParseOptions (char *file_name)
       else if (strncmp (cp, "ItemFore", 8) == 0)
 	{
 	  cp += 8;
-	  while (isspace (*cp))
+	  while (isspace ((unsigned char)*cp))
 	    cp++;
 	  color_names[c_itemfore] = copystring (cp, 0);
 	  fprintf (fp_err, "ColorItemFore: %s\n", color_names[c_itemfore]);
@@ -439,7 +439,7 @@ ParseOptions (char *file_name)
       else if (strncmp (cp, "ItemBack", 8) == 0)
 	{
 	  cp += 8;
-	  while (isspace (*cp))
+	  while (isspace ((unsigned char)*cp))
 	    cp++;
 	  color_names[c_itemback] = copystring (cp, 0);
 	  fprintf (fp_err, "ColorItemBack: %s\n", color_names[c_itemback]);
@@ -448,7 +448,7 @@ ParseOptions (char *file_name)
       else if (strncmp (cp, "Font", 4) == 0)
 	{
 	  cp += 4;
-	  while (isspace (*cp))
+	  while (isspace ((unsigned char)*cp))
 	    cp++;
 	  font_names[f_text] = copystring (cp, 0);
 	  fprintf (fp_err, "Font: %s\n", font_names[f_text]);
@@ -486,7 +486,7 @@ ParseOptions (char *file_name)
       else if (strncmp (cp, "ButtonFont", 10) == 0)
 	{
 	  cp += 10;
-	  while (isspace (*cp))
+	  while (isspace ((unsigned char)*cp))
 	    cp++;
 	  font_names[f_button] = copystring (cp, 0);
 	  fprintf (fp_err, "ButtonFont: %s\n", font_names[f_button]);
@@ -524,7 +524,7 @@ ParseOptions (char *file_name)
       else if (strncmp (cp, "InputFont", 9) == 0)
 	{
 	  cp += 9;
-	  while (isspace (*cp))
+	  while (isspace ((unsigned char)*cp))
 	    cp++;
 	  font_names[f_input] = copystring (cp, 0);
 	  fprintf (fp_err, "InputFont: %s\n", font_names[f_input]);
@@ -563,7 +563,7 @@ ParseOptions (char *file_name)
 	{
 	  cp += 4;
 	  cur_line = lines + n_lines++;
-	  while (isspace (*cp))
+	  while (isspace ((unsigned char)*cp))
 	    cp++;
 	  if (strncmp (cp, "left", 4) == 0)
 	    cur_line->justify = L_LEFT;
@@ -584,7 +584,7 @@ ParseOptions (char *file_name)
 	  item = items + n_items++;
 	  item->type = I_TEXT;
 	  item->header.name = "";
-	  while (isspace (*cp))
+	  while (isspace ((unsigned char)*cp))
 	    cp++;
 	  if (*cp == '\"')
 	    item->text.value = CopyQuotedString (++cp);
@@ -610,16 +610,16 @@ ParseOptions (char *file_name)
 	  cp += 5;
 	  item = items + n_items++;
 	  item->type = I_INPUT;
-	  while (isspace (*cp))
+	  while (isspace ((unsigned char)*cp))
 	    cp++;
 	  item->header.name = CopySolidString (cp);
 	  cp += strlen (item->header.name);
-	  while (isspace (*cp))
+	  while (isspace ((unsigned char)*cp))
 	    cp++;
 	  item->input.size = atoi (cp);
-	  while (!isspace (*cp))
+	  while (!isspace ((unsigned char)*cp))
 	    cp++;
-	  while (isspace (*cp))
+	  while (isspace ((unsigned char)*cp))
 	    cp++;
 	  if (*cp == '\"')
 	    item->input.init_value = CopyQuotedString (++cp);
@@ -644,11 +644,11 @@ ParseOptions (char *file_name)
 	  cp += 9;
 	  cur_sel = items + n_items++;
 	  cur_sel->type = I_SELECT;
-	  while (isspace (*cp))
+	  while (isspace ((unsigned char)*cp))
 	    cp++;
 	  cur_sel->header.name = CopySolidString (cp);
 	  cp += strlen (cur_sel->header.name);
-	  while (isspace (*cp))
+	  while (isspace ((unsigned char)*cp))
 	    cp++;
 	  if (strncmp (cp, "multiple", 8) == 0)
 	    cur_sel->select.key = IS_MULTIPLE;
@@ -665,23 +665,23 @@ ParseOptions (char *file_name)
 	  cp += 6;
 	  item = items + n_items++;
 	  item->type = I_CHOICE;
-	  while (isspace (*cp))
+	  while (isspace ((unsigned char)*cp))
 	    cp++;
 	  item->header.name = CopySolidString (cp);
 	  cp += strlen (item->header.name);
-	  while (isspace (*cp))
+	  while (isspace ((unsigned char)*cp))
 	    cp++;
 	  item->choice.value = CopySolidString (cp);
 	  cp += strlen (item->choice.value);
-	  while (isspace (*cp))
+	  while (isspace ((unsigned char)*cp))
 	    cp++;
 	  if (strncmp (cp, "on", 2) == 0)
 	    item->choice.init_on = 1;
 	  else
 	    item->choice.init_on = 0;
-	  while (!isspace (*cp))
+	  while (!isspace ((unsigned char)*cp))
 	    cp++;
-	  while (isspace (*cp))
+	  while (isspace ((unsigned char)*cp))
 	    cp++;
 	  if (*cp == '\"')
 	    item->choice.text = CopyQuotedString (++cp);
@@ -709,7 +709,7 @@ ParseOptions (char *file_name)
 	  item = items + n_items++;
 	  item->type = I_BUTTON;
 	  item->header.name = "";
-	  while (isspace (*cp))
+	  while (isspace ((unsigned char)*cp))
 	    cp++;
 	  if (strncmp (cp, "restart", 7) == 0)
 	    item->button.key = IB_RESTART;
@@ -717,15 +717,15 @@ ParseOptions (char *file_name)
 	    item->button.key = IB_QUIT;
 	  else
 	    item->button.key = IB_CONTINUE;
-	  while (!isspace (*cp))
+	  while (!isspace ((unsigned char)*cp))
 	    cp++;
-	  while (isspace (*cp))
+	  while (isspace ((unsigned char)*cp))
 	    cp++;
 	  if (*cp == '\"')
 	    {
 	      item->button.text = CopyQuotedString (++cp);
 	      cp += strlen (item->button.text) + 1;
-	      while (isspace (*cp))
+	      while (isspace ((unsigned char)*cp))
 		cp++;
 	    }
 	  else
@@ -755,7 +755,7 @@ ParseOptions (char *file_name)
 	{
 /* syntax: *FFCommand <command> */
 	  cp += 7;
-	  while (isspace (*cp))
+	  while (isspace ((unsigned char)*cp))
 	    cp++;
 	  cur_button->button.commands[cur_button->button.n++] =
 	    copystring (cp, 0);
@@ -1276,7 +1276,7 @@ ParseCommand (int dn, char *sp, char end
 		  *(vp++) = '\0';
 		  break;
 		}
-	      else if (!isspace (x))
+	      else if (!isspace ((unsigned char)x))
 		*(vp++) = x;
 	    }
 	  for (i = 0; i < n_items; i++)
@@ -1291,7 +1291,7 @@ ParseCommand (int dn, char *sp, char end
 			{
 			  for (cp = item->input.value; *cp != '\0'; cp++)
 			    {
-			      if (!isalnum (*cp))
+			      if (!isalnum ((unsigned char)*cp))
 				AddChar ('\\');
 			      AddChar (*cp);
 			    }
