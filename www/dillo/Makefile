# $NetBSD: Makefile,v 1.6.2.2 2002/06/30 06:24:32 jlam Exp $
#

DISTNAME=	dillo-0.6.5
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://dillo.cipsga.org.br/download/

MAINTAINER=	Benjamin.Wong@cc.gatech.edu
HOMEPAGE=	http://dillo.cipsga.org.br/
COMMENT=	Very small and fast graphical web-browser

USE_BUILDLINK2=	yes
USE_X11=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dillo
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/dillo

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
