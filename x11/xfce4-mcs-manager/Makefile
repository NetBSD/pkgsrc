# $NetBSD: Makefile,v 1.4 2004/01/03 18:50:00 reed Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce-mcs-manager-${XFCE4_VERSION}
PKGNAME=	xfce4-mcs-manager-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	XFce4 settings manager

PKGCONFIG_OVERRIDE=	xfce-mcs-manager/xfce-mcs-manager.pc.in

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../x11/libxfce4gui/buildlink2.mk"
.include "../../x11/libxfce4mcs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
