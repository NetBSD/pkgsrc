# $NetBSD: Makefile,v 1.1.1.1 2003/09/26 10:40:05 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

PKGNAME=	libxfce4gui-${XFCE4_VERSION}
DISTNAME=	libxfcegui4-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	XFce4 widget library

PKGCONFIG_OVERRIDE=	libxfcegui4/libxfcegui4-1.0.pc.in

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../x11/libxfce4util/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
