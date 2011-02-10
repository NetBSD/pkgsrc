$NetBSD: patch-http__load.c,v 1.1 2011/02/10 12:36:31 obache Exp $

* need to initialize Internet family

--- http_load.c.orig	2006-03-12 19:17:03.000000000 +0000
+++ http_load.c
@@ -785,6 +785,7 @@ read_sip_file( char* sip_file )
 		argv0, sips[num_sips].str );
 	    exit( 1 );
 	    }
+	sips[num_sips].sa.sin_family = AF_INET;
 	++num_sips;
 	}
     }
