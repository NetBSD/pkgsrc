# $NetBSD: Makefile,v 1.5 2004/01/08 08:11:42 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce-mcs-manager-${XFCE4_VERSION}
PKGNAME=	xfce4-mcs-manager-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	XFce4 settings manager

PKGCONFIG_OVERRIDE=	xfce-mcs-manager/xfce-mcs-manager.pc.in

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../x11/libxfce4gui/buildlink2.mk"
.include "../../x11/libxfce4mcs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
