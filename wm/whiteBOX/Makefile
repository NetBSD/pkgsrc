# $NetBSD: Makefile,v 1.9 2004/01/24 15:18:32 grant Exp $
#

DISTNAME=	whiteBOX-0.5
PKGREVISION=	2
CATEGORIES=	wm x11
MASTER_SITES=	http://whitebox.sourceforge.net/dist/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://whitebox.sourceforge.net/
COMMENT=	Multi-purpose configuration tool for Blackbox

USE_BUILDLINK2=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

# this prevents us from build-depending on autoconf and automake
# is it worth it?
pre-install:
	${RM} -f ${WRKSRC}/mkinstalldirs
	${ECHO} "#!${SH}" > ${WRKSRC}/mkinstalldirs
	${ECHO} "${ECHO}" >> ${WRKSRC}/mkinstalldirs
	${CHMOD} 755  ${WRKSRC}/mkinstalldirs
	${INSTALL_DATA_DIR} ${PREFIX}/share/whiteBOX/pixmaps
	${INSTALL_DATA_DIR} ${PREFIX}/share/whiteBOX/plugins

.include "../../graphics/gdk-pixbuf/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
