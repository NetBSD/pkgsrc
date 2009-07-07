# $NetBSD: Makefile,v 1.2 2009/07/07 21:35:23 joerg Exp $
#

DISTNAME=	transset-df-5
CATEGORIES=	x11
MASTER_SITES=	http://forchheimer.se/transset-df/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://forchheimer.se/transset-df/
COMMENT=	Patched version of xorg's transset

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=	transset-df
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/transset-df ${DESTDIR}${PREFIX}/bin

.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
