$NetBSD: patch-options.c,v 1.1 2020/11/24 10:25:24 nia Exp $

Argument to ctype functions must be unsigned char.

--- options.c.orig	2020-05-23 16:22:19.000000000 +0000
+++ options.c
@@ -708,7 +708,7 @@ get_rc_file (void)
 			  /* is a numeric keycode (c:nnn) ? */
 			  if (line2[0] == 'c' && line2[1] == ':')
 			    {
-			      if (isdigit (line2[2]))
+			      if (isdigit ((unsigned char)line2[2]))
 				{
 				  type = CODE;
 				  keycode = strtol (line2+2, (char **) NULL, 0);
@@ -725,7 +725,7 @@ get_rc_file (void)
 			    /* is a numeric modifier (m:nnn) ? */
 			  if (line2[0] == 'm' && line2[1] == ':')
 			    {
-			      if (isdigit (line2[2]))
+			      if (isdigit ((unsigned char)line2[2]))
 				{
 				  modifier |= strtol (line2+2, (char **) NULL, 0);
 				}
@@ -741,7 +741,7 @@ get_rc_file (void)
 			    /* is a mouse button (b:nnn) ? */
 			  if (line2[0] == 'b' && line2[1] == ':')
 			    {
-			      if (isdigit (line2[2]))
+			      if (isdigit ((unsigned char)line2[2]))
 				{
 				  type = BUTTON;
 				  button = strtol (line2+2, (char **) NULL, 0);
@@ -967,7 +967,7 @@ SCM extract_key (SCM key, KeyType_t *typ
   //Check for special numeric stuff.
   //This way is really far nicer looking and more efficient than
   //having three copies of the code.
-  if(strlen (str) > 2 && str[1] == ':' && isdigit (str[2]))
+  if(strlen (str) > 2 && str[1] == ':' && isdigit ((unsigned char)str[2]))
     {
       switch (str[0])
         {
