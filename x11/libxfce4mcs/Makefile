# $NetBSD: Makefile,v 1.2 2004/03/10 11:53:37 xtraeme Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	libxfce4mcs-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	XFce4 settings management library

PKGCONFIG_OVERRIDE=	libxfce4mcs/libxfce4mcs-client-1.0.pc.in
PKGCONFIG_OVERRIDE+=	libxfce4mcs/libxfce4mcs-manager-1.0.pc.in

.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
