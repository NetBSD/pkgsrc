# $NetBSD: builtin.mk,v 1.1 2017/01/24 14:25:00 mrg Exp $

BUILTIN_PKG:=	libXpresent
PKGCONFIG_FILE.libXpresent=	${X11BASE}/lib/pkgconfig/xpresent.pc
PKGCONFIG_FILE.libXpresent+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xpresent.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"

CHECK_BUILTIN.libXpresent?=	no
.if !empty(CHECK_BUILTIN.libXpresent:M[nN][oO])

.  if !empty(USE_BUILTIN.libXpresent:M[nN][oO])
BUILDLINK_API_DEPENDS.presentproto+=	presentproto>=1.0
.  endif

.endif  # CHECK_BUILTIN.libXpresent
