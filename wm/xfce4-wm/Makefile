# $NetBSD: Makefile,v 1.2 2003/12/13 00:45:26 wiz Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfwm4-${XFCE4_VERSION}
PKGNAME=	xfce4-wm-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	wm
COMMENT=	XFce4 window manager

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink2.mk"
.include "../../x11/startup-notification/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
