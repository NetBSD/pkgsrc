# $NetBSD: Makefile,v 1.14 2006/01/24 07:32:41 wiz Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	4.2.3.2

DISTNAME=	xfwm4-${XFCE4_VERSION}
PKGNAME=	xfce4-wm-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	wm
COMMENT=	Xfce window manager

.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
