$NetBSD: patch-security_nss_lib_freebl_mpi_mpi.c,v 1.1 2020/05/30 08:02:52 rillig Exp $

Fix undefined behavior when calling <ctype.h> functions with illegal values.

security/nss/lib/freebl/mpi/mpi.c:4565:15: error: array subscript is of type 'char' [-Werror,-Wchar-subscripts]
        xch = toupper(ch);

security/nss/lib/freebl/mpi/mpi.c:4611:14: error: array subscript is of type 'char' [-Werror,-Wchar-subscripts]
        ch = tolower(ch);

https://bugzilla.mozilla.org/show_bug.cgi?id=1642081

--- security/nss/lib/freebl/mpi/mpi.c.orig	2020-05-07 18:35:01.000000000 +0000
+++ security/nss/lib/freebl/mpi/mpi.c
@@ -4560,9 +4560,9 @@ s_mp_tovalue(char ch, int r)
     int val, xch;
 
     if (r > 36)
-        xch = ch;
+        xch = (unsigned char) ch;
     else
-        xch = toupper(ch);
+        xch = toupper((unsigned char) ch);
 
     if (isdigit(xch))
         val = xch - '0';
@@ -4608,7 +4608,7 @@ s_mp_todigit(mp_digit val, int r, int lo
     ch = s_dmap_1[val];
 
     if (r <= 36 && low)
-        ch = tolower(ch);
+        ch = tolower((unsigned char) ch);
 
     return ch;
 
