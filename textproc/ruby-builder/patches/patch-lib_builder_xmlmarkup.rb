$NetBSD: patch-lib_builder_xmlmarkup.rb,v 1.1 2011/03/27 13:08:20 taca Exp $

* Aboid crash with Ruby 1.8.7's rdoc.

--- lib/builder/xmlmarkup.rb.orig	2011-03-26 16:32:42.000000000 +0000
+++ lib/builder/xmlmarkup.rb
@@ -38,7 +38,6 @@ module Builder
   #       xm.title("History")        #     <title>History</title>
   #     }                            #   </head>
   #     xm.body {                    #   <body>
-  #       xm.comment! "HI"           #     <!-- HI -->
   #       xm.h1("Header")            #     <h1>Header</h1>
   #       xm.p("paragraph")          #     <p>paragraph</p>
   #     }                            #   </body>
