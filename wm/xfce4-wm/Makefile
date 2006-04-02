# $NetBSD: Makefile,v 1.16 2006/04/02 09:49:01 jmmv Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	4.2.3.2

DISTNAME=	xfwm4-${XFCE4_VERSION}
PKGNAME=	xfce4-wm-${XFCE4_VERSION}
PKGREVISION=	3
CATEGORIES=	wm
COMMENT=	Xfce window manager

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
