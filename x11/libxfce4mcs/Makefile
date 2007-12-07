# $NetBSD: Makefile,v 1.15 2007/12/07 19:43:25 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	libxfce4mcs-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	Xfce settings management library

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

PKGCONFIG_OVERRIDE=	libxfce4mcs/libxfce4mcs-client-1.0.pc.in
PKGCONFIG_OVERRIDE+=	libxfce4mcs/libxfce4mcs-manager-1.0.pc.in

.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
