# $NetBSD: Makefile,v 1.1.1.1 2001/12/06 16:15:41 dillo Exp $
#

DISTNAME=	dillo-0.6.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dillo/}

MAINTAINER=	Benjamin.Wong@cc.gatech.edu
HOMEPAGE=	http://dillo.sourceforge.net/
COMMENT=	very small and fast graphical web-browser

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/dillo
	${INSTALL_DATA} ${WRKSRC}/dillorc ${PREFIX}/share/examples/dillo

.include	"../../devel/pth/buildlink.mk"
.include	"../../devel/zlib/buildlink.mk"
.include	"../../x11/gtk/buildlink.mk"
.include	"../../graphics/jpeg/buildlink.mk"
.include	"../../graphics/png/buildlink.mk"

.include "../../mk/bsd.pkg.mk"
