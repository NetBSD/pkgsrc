# $NetBSD: Makefile,v 1.6 2004/03/10 11:53:37 xtraeme Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce-mcs-manager-${XFCE4_VERSION}
PKGNAME=	xfce4-mcs-manager-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	XFce4 settings manager

PKGCONFIG_OVERRIDE=	xfce-mcs-manager/xfce-mcs-manager.pc.in

.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../x11/libxfce4mcs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
