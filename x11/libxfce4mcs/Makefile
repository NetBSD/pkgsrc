# $NetBSD: Makefile,v 1.18 2009/08/26 19:57:02 sno Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	libxfce4mcs-${XFCE4_VERSION}
PKGREVISION=	2
CATEGORIES=	x11
COMMENT=	Xfce settings management library

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

PKGCONFIG_OVERRIDE=	libxfce4mcs/libxfce4mcs-client-1.0.pc.in
PKGCONFIG_OVERRIDE+=	libxfce4mcs/libxfce4mcs-manager-1.0.pc.in

.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
