# $NetBSD: builtin.mk,v 1.5 2014/03/10 11:05:52 jperkin Exp $

BUILTIN_PKG:=	libXrandr
PKGCONFIG_FILE.libXrandr=	${X11BASE}/lib/pkgconfig/xrandr.pc
PKGCONFIG_FILE.libXrandr+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xrandr.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"

CHECK_BUILTIN.libXrandr?=	no
.if !empty(CHECK_BUILTIN.libXrandr:M[nN][oO])

.  if !empty(USE_BUILTIN.libXrandr:M[nN][oO])
BUILDLINK_API_DEPENDS.randrproto+=	randrproto>=1.4
.  endif

.endif  # CHECK_BUILTIN.libXrandr
