$NetBSD: patch-config_pregcomp2.c,v 1.1 2026/01/01 09:36:08 mef Exp $


https://src.fedoraproject.org/rpms/perl-Tk/blob/rawhide/f/perl-Tk-pregcomp2.c-Avoid-using-incompatible-pointer-type.patch

From: Christopher Chavez <chrischavez@gmx.us>
Date: Mon, 19 Feb 2024 13:50:44 -0600
Subject: [PATCH] pregcomp2.c: Avoid using incompatible pointer type

See https://github.com/eserte/perl-tk/issues/98#issuecomment-1948125587


gcc-14.3.0 flags as follows
/export/WRKOBJDIR/x11/p5-Tk/work/.buildlink/lib/perl5/5.42.0/x86_64-netbsd-thread-multi/CORE/embed.h:511:10: note: macro "pregcomp" defined here
  511 | # define pregcomp(a,b)                          Perl_pregcomp(aTHX_ a,b)
      |          ^~~~~~~~
tkGlue.c:5262:11: error: 'pregcomp' undeclared (first use in this function); did you mean 'regcomp_t'?
 5262 |  p->pat = pregcomp(string,string+len,p->flags);
      |           ^~~~~~~~
      |           regcomp_t
tkGlue.c:5262:11: note: each undeclared identifier is reported only once for each function it appears in
*** Error code 1


--- config/pregcomp2.c
+++ config/pregcomp2.c
@@ -4,5 +4,5 @@
 
 int main() {
     SV* sv = newSViv(0);
-    regexp* rx = pregcomp(sv, 0);
+    void* rx = pregcomp(sv, 0);
 }
