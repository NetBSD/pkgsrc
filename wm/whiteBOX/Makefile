# $NetBSD: Makefile,v 1.17 2006/02/05 23:11:15 joerg Exp $
#

DISTNAME=	whiteBOX-0.5
PKGREVISION=	5
CATEGORIES=	wm x11
MASTER_SITES=	http://whitebox.sourceforge.net/dist/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://whitebox.sourceforge.net/
COMMENT=	Multi-purpose configuration tool for Blackbox

USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

# this prevents us from build-depending on autoconf and automake
# is it worth it?
pre-install:
	${RM} -f ${WRKSRC}/mkinstalldirs
	${ECHO} "#!${SH}" > ${WRKSRC}/mkinstalldirs
	${ECHO} "${ECHO}" >> ${WRKSRC}/mkinstalldirs
	${CHMOD} 755  ${WRKSRC}/mkinstalldirs
	${INSTALL_DATA_DIR} ${PREFIX}/share/whiteBOX/pixmaps
	${INSTALL_DATA_DIR} ${PREFIX}/share/whiteBOX/plugins

.include "../../graphics/gdk-pixbuf/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
