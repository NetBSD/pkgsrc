# $NetBSD: Makefile,v 1.12 2004/04/20 19:41:35 minskim Exp $
#

DISTNAME=	catclock
PKGNAME=	catclock-0.0
PKGREVISION=	2
CATEGORIES=	x11 time
MASTER_SITES=	http://www2.cenaath.cena.dgac.fr/ftp/decwindows/ \
		ftp://ftp2.cnam.fr/decwindows/ \
		ftp://ftp.wku.edu/vms/decwindows/ \
		ftp://sunsite.doc.ic.ac.uk/computing/graphics/systems/X11/contrib/vms/
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Variant of the MIT xclock with a "cat" mode

USE_BUILDLINK3=	yes
USE_IMAKE=	yes

post-patch:
	${RM} ${WRKSRC}/makefile ${WRKSRC}/pwd.h
	${MV} ${WRKSRC}/xclock.man ${WRKSRC}/catclock.man
	${SED} 's/^XClock/Catclock/g' <${WRKSRC}/xclock.ad >${WRKSRC}/Catclock.ad

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
