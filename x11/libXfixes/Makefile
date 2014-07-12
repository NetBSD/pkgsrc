# $NetBSD: Makefile,v 1.9 2014/07/12 11:24:52 obache Exp $

DISTNAME=		libXfixes-5.0.1
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Xfixes library and extension of X RandR from modular X.org
LICENSE=		mit

CONFLICTS+=		Xfixes-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3
PKGCONFIG_OVERRIDE+=	xfixes.pc.in

BUILDLINK_API_DEPENDS.fixesproto+=	fixesproto>=5.0
.include "../../x11/fixesproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
