# $NetBSD: hacks.mk,v 1.4 2009/12/16 22:28:32 tnn Exp $
#
.if !defined(PIXMAN_HACKS_MK)
PIXMAN_HACKS_MK=	# empty
.  include "../../mk/bsd.fast.prefs.mk"
.  include "../../mk/compiler.mk"
###
### XXX SSE2 intrinsics require gcc-4.2+ to build unless
###	${MACHINE_ARCH} == "x86_64".
###
.if (empty(MACHINE_ARCH:Mx86_64) && \
     (empty(CC_VERSION:Mgcc-4.[2-9]*) || empty(CC_VERSION:Mgcc-[5-9].*) || empty(CC_VERSION:Mgcc-[1-9][0-9]*)))
CONFIGURE_ARGS+=	--disable-sse2
.  endif
.endif

.if !empty(PKGSRC_COMPILER:Msunpro)
CONFIGURE_ARGS+=	--disable-sse2 --disable-mmx
.endif
