# $NetBSD: Makefile,v 1.15 2011/06/12 00:21:53 dholland Exp $
#

DISTNAME=		libXi-1.4.3
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X Input extension library
LICENSE=		mit

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3 ac_cv_path_ASCIIDOC= ac_cv_path_XMLTO=
PKGCONFIG_OVERRIDE+=	xi.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--disable-malloc0returnsnull
.endif

BUILDLINK_API_DEPENDS.inputproto+=	inputproto>=2.0
BUILDLINK_API_DEPENDS.libX11+=		libX11>=1.3
BUILDLINK_API_DEPENDS.libXext+=		libXext>=1.1
BUILDLINK_API_DEPENDS.xextproto+=	xextproto>=7.0.3
BUILDLINK_API_DEPENDS.xproto+=		xproto>=7.0.13
.include "../../x11/inputproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
