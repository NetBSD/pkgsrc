# $NetBSD: Makefile,v 1.6 2001/09/12 03:47:27 jlam Exp $
#

DISTNAME=	catclock
PKGNAME=	catclock-0.0
CATEGORIES=	x11 time
MASTER_SITES=	http://www2.cenaath.cena.dgac.fr/ftp/decwindows/ \
	ftp://ftp2.cnam.fr/decwindows/ \
	ftp://ftp.wku.edu/vms/decwindows/ \
	ftp://sunsite.doc.ic.ac.uk/computing/graphics/systems/X11/contrib/vms/
EXTRACT_SUFX=	.zip

MAINTAINER=	packages@netbsd.org
COMMENT=	Variant of the MIT xclock with a "cat" mode

USE_IMAKE=	yes

post-extract:
	${RM} ${WRKSRC}/makefile ${WRKSRC}/pwd.h
	${MV} ${WRKSRC}/xclock.man ${WRKSRC}/catclock.man
	${SED} 's/^XClock/Catclock/g' <${WRKSRC}/xclock.ad >${WRKSRC}/Catclock.ad

.include "../../mk/motif.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
