# $NetBSD: Makefile,v 1.17 2006/04/17 13:46:13 wiz Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	4.2.3.2

DISTNAME=	xfwm4-${XFCE4_VERSION}
PKGNAME=	xfce4-wm-${XFCE4_VERSION}
PKGREVISION=	4
CATEGORIES=	wm
COMMENT=	Xfce window manager

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
