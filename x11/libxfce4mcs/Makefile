# $NetBSD: Makefile,v 1.3 2004/10/03 00:18:36 tv Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	libxfce4mcs-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	XFce4 settings management library

PKGCONFIG_OVERRIDE=	libxfce4mcs/libxfce4mcs-client-1.0.pc.in
PKGCONFIG_OVERRIDE+=	libxfce4mcs/libxfce4mcs-manager-1.0.pc.in

.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
