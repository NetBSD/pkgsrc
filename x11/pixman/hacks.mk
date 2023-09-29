# $NetBSD: hacks.mk,v 1.15 2023/09/29 09:27:07 adam Exp $
#
.if !defined(PIXMAN_HACKS_MK)
PIXMAN_HACKS_MK=	# empty
.include "../../mk/bsd.fast.prefs.mk"
.include "../../mk/compiler.mk"
###
### XXX SSE2 intrinsics require gcc-4.2+ to build.
### XXX Need to disable SSSE3 explicitly, too.
###
.  if !${CC_VERSION:Mgcc-4.[2-9]*} && \
    !${CC_VERSION:Mgcc-[5-9].*} && \
    !${CC_VERSION:Mgcc-[1-9][0-9]*}
CONFIGURE_ARGS+=	--disable-sse2 --disable-ssse3
.  endif
.endif

.if !empty(PKGSRC_COMPILER:Msunpro)
CONFIGURE_ARGS+=	--disable-sse2 --disable-mmx --disable-ssse3
.endif

CONFIGURE_ARGS.MirBSD+=	PTHREAD_LIBS=-pthread

.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 060000
CONFIGURE_ENV+=		ac_cv_tls=none
CFLAGS+=		-DPIXMAN_NO_TLS
.endif
