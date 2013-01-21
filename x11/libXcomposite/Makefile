# $NetBSD: Makefile,v 1.9 2013/01/21 13:26:46 wiz Exp $
#

DISTNAME=		libXcomposite-0.4.4
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X Composite Library
LICENSE=		mit

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xcomposite.pc.in

BUILDLINK_API_DEPENDS.compositeproto+=	compositeproto>=0.4

.include "../../x11/compositeproto/buildlink3.mk"
.include "../../x11/fixesproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
