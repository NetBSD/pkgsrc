# $NetBSD: hacks.mk,v 1.2 2024/03/11 08:59:16 wiz Exp $

.if !defined(LIBXAW_HACKS_MK)
LIBXAW_HACKS_MK=	# defined

.include "../../mk/compiler.mk"

.if ${CC_VERSION:Mgcc-[34]*}
CFLAGS+=	-fno-strict-aliasing
PKG_HACKS+=	no-strict-aliasing
.endif

.endif
