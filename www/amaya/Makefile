# $NetBSD: Makefile,v 1.8 2001/05/22 09:32:26 wiz Exp $

DISTNAME=	amaya-src-4.3.2
PKGNAME=	amaya-4.3.2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.w3.org/pub/amaya/
EXTRACT_SUFX=	.tgz

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://www.w3.org/Amaya/
COMMENT=	Web Browser/Editor from the World Wide Web Consortium

WRKSRC=		${WRKDIR}/Amaya/work
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS+=	--with-motif --without-graphic-libs
CONFIGURE_ENV+=	MOTIFBASE=${MOTIFBASE}
CFLAGS+=	-Dunix

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png>=1.0.11:../../graphics/png

USE_MOTIF=	yes
USE_GMAKE=	yes

post-extract:
	${MKDIR} ${WRKSRC}
	${RM} -rf ${WRKDIR}/Amaya/libjpeg
	${RM} -rf ${WRKDIR}/Amaya/libpng/zlib
	${RM} -rf ${WRKDIR}/Amaya/libpng

.include "../../mk/bsd.pkg.mk"
