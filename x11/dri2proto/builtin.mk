# $NetBSD: builtin.mk,v 1.1.1.1 2009/05/19 06:34:41 hasso Exp $

BUILTIN_PKG:=	dri2proto
PKGCONFIG_FILE.dri2proto=	${X11BASE}/lib/pkgconfig/dri2proto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
