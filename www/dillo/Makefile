# $NetBSD: Makefile,v 1.2 2001/12/06 16:36:28 jlam Exp $
#

DISTNAME=	dillo-0.6.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dillo/}

MAINTAINER=	Benjamin.Wong@cc.gatech.edu
HOMEPAGE=	http://dillo.sourceforge.net/
COMMENT=	very small and fast graphical web-browser

USE_BUILDLINK_ONLY=	yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/dillo
	${INSTALL_DATA} ${WRKSRC}/dillorc ${PREFIX}/share/examples/dillo

.include	"../../devel/pth/buildlink.mk"
.include	"../../graphics/jpeg/buildlink.mk"
.include	"../../graphics/png/buildlink.mk"
.include	"../../x11/gtk/buildlink.mk"
.include	"../../mk/x11.buildlink.mk"

.include "../../mk/bsd.pkg.mk"
