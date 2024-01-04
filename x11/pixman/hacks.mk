# $NetBSD: hacks.mk,v 1.16 2024/01/04 11:33:38 wiz Exp $
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
MESON_ARGS+=	-Dsse2=disabled
MESON_ARGS+=	-Dssse3=disabled
.  endif
.endif

.if !empty(PKGSRC_COMPILER:Msunpro)
MESON_ARGS+=	-Dmmx=disabled
MESON_ARGS+=	-Dsse2=disabled
MESON_ARGS+=	-Dssse3=disabled
.endif
