# $NetBSD: Makefile,v 1.4 2004/01/03 18:49:59 reed Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	libxfcegui4-${XFCE4_VERSION}
PKGNAME=	libxfce4gui-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	XFce4 widget library

PKGCONFIG_OVERRIDE=	libxfcegui4/libxfcegui4-1.0.pc.in

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../x11/libxfce4util/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
