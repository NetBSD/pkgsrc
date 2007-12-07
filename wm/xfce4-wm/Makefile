# $NetBSD: Makefile,v 1.25 2007/12/07 19:43:23 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfwm4-${XFCE4_VERSION}
PKGNAME=	xfce4-wm-${XFCE4_VERSION}
#PKGREVISION=	1
CATEGORIES=	wm
COMMENT=	Xfce window manager

USE_DIRS+=	xdg-1.4

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
