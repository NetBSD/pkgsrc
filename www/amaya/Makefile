# $NetBSD: Makefile,v 1.1.1.1 2000/06/20 16:50:08 drochner Exp $
#

DISTNAME=	amaya-src-3.1
PKGNAME=	amaya-3.1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.w3.org/pub/amaya/
EXTRACT_SUFX=	.tgz

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://www.w3.org/Amaya/

WRKSRC=		${WRKDIR}/Amaya/work
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../configure

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png>=1.0.1:../../graphics/png

USE_MOTIF=	yes
USE_GMAKE=	yes

post-extract:
	${MKDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
