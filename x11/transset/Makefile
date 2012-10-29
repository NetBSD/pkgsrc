# $NetBSD: Makefile,v 1.2 2012/10/29 05:06:54 asau Exp $
#

DISTNAME=	transset-1.0.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Utility for setting opacity property

GNU_CONFIGURE=	yes

USE_TOOLS+=	pkg-config

#INSTALLATION_DIRS=	bin

#do-install:
#	${INSTALL_PROGRAM} ${WRKSRC}/transset-df ${DESTDIR}${PREFIX}/bin

.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
