# $NetBSD: hacks.mk,v 1.1 2015/12/14 16:49:22 bouyer Exp $

### [Mon Dec 14 16:58:00 MET 2015 : bouyer ]
### g++-4.5.3 and 4.5.4 on NetBSD/i386 fails with an internal compiler error
### when PCH is used. Be conservative and disable on all MACHINE_ARCH
### 
.if ${OPSYS} == "NetBSD" 
.  include "../../mk/compiler.mk"
.  if !empty(CC_VERSION:Mgcc-4.8.*)
CONFIGURE_ARGS+=	--disable-precomp-headers
.endif
.endif
