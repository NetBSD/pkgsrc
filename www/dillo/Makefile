# $NetBSD: Makefile,v 1.7 2002/05/21 11:13:30 wiz Exp $
#

DISTNAME=	dillo-0.6.5
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://dillo.cipsga.org.br/download/

MAINTAINER=	Benjamin.Wong@cc.gatech.edu
HOMEPAGE=	http://dillo.cipsga.org.br/
COMMENT=	Very small and fast graphical web-browser

USE_BUILDLINK_ONLY=	yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dillo
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/dillo

.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
