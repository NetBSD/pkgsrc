# $NetBSD: Makefile,v 1.12 2004/04/25 04:16:43 xtraeme Exp $
#

DISTNAME=	whiteBOX-0.5
PKGREVISION=	3
CATEGORIES=	wm x11
MASTER_SITES=	http://whitebox.sourceforge.net/dist/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://whitebox.sourceforge.net/
COMMENT=	Multi-purpose configuration tool for Blackbox

USE_BUILDLINK3=	YES
USE_X11=	YES
USE_GNU_TOOLS+=	make
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
