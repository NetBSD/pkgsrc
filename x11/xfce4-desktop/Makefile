# $NetBSD: Makefile,v 1.1.1.1 2003/09/26 10:41:55 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

PKGNAME=	xfce4-desktop-${XFCE4_VERSION}
DISTNAME=	xfdesktop-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	XFce4 desktop background manager

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink2.mk"
.include "../../x11/startup-notification/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
