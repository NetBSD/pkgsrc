# $NetBSD: Makefile,v 1.2 1999/09/09 16:32:36 tron Exp $

DISTNAME=	catclock
PKGNAME=	catclock-0.0
CATEGORIES=	x11
MASTER_SITES=	http://www2.cenaath.cena.dgac.fr/ftp/decwindows/ \
	ftp://ftp2.cnam.fr/decwindows/ \
	ftp://ftp.wku.edu/vms/decwindows/ \
	ftp://sunsite.doc.ic.ac.uk/computing/graphics/systems/X11/contrib/vms/
EXTRACT_SUFX=	.zip

MAINTAINER=	packages@netbsd.org

BUILD_DEPENDS=	unzip:../../archivers/unzip

USE_IMAKE=	yes
USE_MOTIF=	yes

EXTRACT_CMD=	unzip ${DOWNLOADED_DISTFILE}

post-extract:
	${RM} ${WRKSRC}/makefile ${WRKSRC}/pwd.h
	${MV} ${WRKSRC}/xclock.man ${WRKSRC}/catclock.man
	${SED} 's/^XClock/Catclock/g' <${WRKSRC}/xclock.ad >${WRKSRC}/Catclock.ad

.include "../../mk/bsd.pkg.mk"
