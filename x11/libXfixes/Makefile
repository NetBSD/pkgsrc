# $NetBSD: Makefile,v 1.11 2016/05/26 09:04:57 wiz Exp $

DISTNAME=		libXfixes-5.0.2
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Xfixes library and extension of X RandR from modular X.org
LICENSE=		mit

CONFLICTS+=		Xfixes-[0-9]*

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3
PKGCONFIG_OVERRIDE+=	xfixes.pc.in

BUILDLINK_API_DEPENDS.fixesproto+=	fixesproto>=5.0
.include "../../x11/fixesproto/buildlink3.mk"
BUILDLINK_API_DEPENDS.libX11+=		libX11>=1.6
.include "../../x11/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
