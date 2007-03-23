# $NetBSD: Makefile,v 1.1.1.1 2007/03/23 17:56:11 drochner Exp $
#

DISTNAME=	transset-df-5
CATEGORIES=	x11
MASTER_SITES=	http://forchheimer.se/transset-df/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://forchheimer.se/transset-df/
COMMENT=	Patched version of xorg's transset

BUILD_TARGET=	transset-df
USE_TOOLS+=	pkg-config

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/transset-df ${PREFIX}/bin

.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
