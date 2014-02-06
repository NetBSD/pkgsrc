# $NetBSD: builtin.mk,v 1.4 2014/02/06 05:34:48 obache Exp $

BUILTIN_PKG:=	libXrandr
PKGCONFIG_FILE.libXrandr=	${X11BASE}/lib/pkgconfig/xrandr.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"

CHECK_BUILTIN.libXrandr?=	no
.if !empty(CHECK_BUILTIN.libXrandr:M[nN][oO])

.  if !empty(USE_BUILTIN.libXrandr:M[nN][oO])
BUILDLINK_API_DEPENDS.randrproto+=	randrproto>=1.4
.  endif

.endif  # CHECK_BUILTIN.libXrandr
