# $NetBSD: hacks.mk,v 1.1.2.2 2011/08/25 13:25:19 sbd Exp $

### [Wed Aug  3 12:18:16 UTC 2011 : tron]
### If "qmake" is build with "-O2" or better with "g++" under Mac OS X the
### resulting binary will crash. This fixes PR pkg/44716 by Richard Hansen.
.if ${OPSYS} == "Darwin"
.  include "../../mk/compiler.mk"
.  if !empty(CC_VERSION:Mgcc*)
PKG_HACKS+=		macosx-codegen
BUILDLINK_TRANSFORM+=	rename:-O[0-9]*:-O1
.  endif
.endif
