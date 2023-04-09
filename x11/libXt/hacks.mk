# $NetBSD: hacks.mk,v 1.2 2023/04/09 21:44:13 wiz Exp $

.if !defined(LIBXT_HACKS_MK)
LIBXT_HACKS_MK=	# defined

.include "../../mk/compiler.mk"

.if ${CC_VERSION:Mgcc-[34]*}
CFLAGS+=	-fno-strict-aliasing
PKG_HACKS+=	no-strict-aliasing
.endif

.endif
