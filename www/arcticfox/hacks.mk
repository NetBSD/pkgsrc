# $NetBSD: hacks.mk,v 1.1 2024/10/03 20:57:34 nia Exp $

.if !defined(ARCTICFOX_HACKS_MK)
ARCTICFOX_HACKS_MK=	# defined

### [Thu Oct  3 19:30:24 CEST 2024 : nia]
### Work around segfaults on startup due to a compiler bug
### before GCC 12. Help from riccardo.
###
.include "../../mk/compiler.mk"
.if ${CC_VERSION:Mgcc-[0-9].*} || ${CC_VERSION:Mgcc-10.*}
CFLAGS+=		-fno-delete-null-pointer-checks
CFLAGS+=		-fno-lifetime-dse
CFLAGS+=		-fno-schedule-insns2
.endif

.endif
