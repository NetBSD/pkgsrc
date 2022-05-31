$NetBSD: patch-driver_passwd-pwent.c,v 1.1 2022/05/31 08:14:44 abs Exp $

Limit "terminating pw_passwd at first ," behaviour to HP-UX, as
it breaks at least argon2 passwords on NetBSD

--- driver/passwd-pwent.c.orig	2021-10-04 22:18:28.082371172 +0000
+++ driver/passwd-pwent.c
@@ -163,6 +163,7 @@ get_encrypted_passwd (const char *user)
         result = strdup(p->pw_passwd);
     }
 
+#ifdef HAVE_HPUX_PASSWD
   /* The manual for passwd(4) on HPUX 10.10 says:
 
 	  Password aging is put in effect for a particular user if his
@@ -173,6 +174,10 @@ get_encrypted_passwd (const char *user)
      So this means that passwd->pw_passwd isn't simply a string of cyphertext,
      it might have trailing junk.  So, if there is a comma in the string, and
      that comma is beyond position 13, terminate the string before the comma.
+
+     Note: This behaviour can break other systems where comma separated data
+     is significant, such as argon2 passwords on NetBSD, so conditionalise
+     to HAVE_HPUX_PASSWD
    */
   if (result && strlen(result) > 13)
     {
@@ -180,6 +185,7 @@ get_encrypted_passwd (const char *user)
       if (s)
 	*s = 0;
     }
+# endif /* HAVE_HPUX_PASSWD */
 
   /* We only issue this warning in non-verbose mode if not compiled with
      support for PAM.  If we're using PAM, it's common for pwent passwords
