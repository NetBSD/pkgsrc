# $NetBSD: Makefile,v 1.1.1.1 2003/09/26 10:37:58 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

PKGNAME=	xfce4-wm-${XFCE4_VERSION}
DISTNAME=	xfwm4-${XFCE4_VERSION}
CATEGORIES=	wm
COMMENT=	XFce4 window manager

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink2.mk"
.include "../../x11/startup-notification/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
