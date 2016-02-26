# $NetBSD: hacks.mk,v 1.12 2016/02/26 11:27:16 jperkin Exp $
#
.if !defined(PIXMAN_HACKS_MK)
PIXMAN_HACKS_MK=	# empty
.  include "../../mk/bsd.fast.prefs.mk"
.  include "../../mk/compiler.mk"
###
### XXX SSE2 intrinsics require gcc-4.2+ to build.
### XXX Need to disable SSSE3 explicitly, too.
###
.if empty(CC_VERSION:Mgcc-4.[2-9]*) && \
    empty(CC_VERSION:Mgcc-[5-9].*) && \
    empty(CC_VERSION:Mgcc-[1-9][0-9]*)
CONFIGURE_ARGS+=	--disable-sse2 --disable-ssse3
.endif
.endif

.if !empty(PKGSRC_COMPILER:Msunpro)
CONFIGURE_ARGS+=	--disable-sse2 --disable-mmx --disable-ssse3
.endif

CONFIGURE_ARGS.MirBSD+=	PTHREAD_LIBS=-pthread

.if !empty(MACHINE_PLATFORM:MNetBSD-[0-5].*-*)
CONFIGURE_ENV+=		ac_cv_tls=none
CFLAGS+=		-DPIXMAN_NO_TLS
.endif
