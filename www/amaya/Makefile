# $NetBSD: Makefile,v 1.2 2000/10/06 14:04:07 agc Exp $
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
CONFIGURE_ARGS+=	--with-motif
CONFIGURE_ENV+=	MOTIFBASE=${MOTIFBASE}
CFLAGS+=	-Dunix

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png>=1.0.1:../../graphics/png

USE_MOTIF=	yes
USE_GMAKE=	yes

post-extract:
	${MKDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
