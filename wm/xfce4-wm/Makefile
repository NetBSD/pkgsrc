# $NetBSD: Makefile,v 1.6 2004/01/13 06:55:25 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	4.0.3.1

DISTNAME=	xfwm4-${XFCE4_VERSION}
PKGNAME=	xfce4-wm-${XFCE4_VERSION}
CATEGORIES=	wm
COMMENT=	XFce4 window manager

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink2.mk"
.include "../../x11/startup-notification/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
