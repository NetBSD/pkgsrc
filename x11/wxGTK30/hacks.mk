# $NetBSD: hacks.mk,v 1.7 2018/04/13 11:43:55 bouyer Exp $

### [Mon Dec 14 16:58:00 MET 2015 : bouyer ]
### g++-4.8 on NetBSD/i386 fails with an internal compiler error
### when PCH is used. Be conservative and disable on all MACHINE_ARCH
###
.if ${OPSYS} == "NetBSD"
.  include "../../mk/compiler.mk"
.  if !empty(PKGSRC_COMPILER:Mgcc) && \
      (!empty(CC_VERSION:Mgcc-4.8.*) || !empty(CC_VERSION:Mgcc-5.*) || !empty(CC_VERSION:Mgcc-6.*))
CONFIGURE_ARGS+=	--disable-precomp-headers
.  endif
.endif
