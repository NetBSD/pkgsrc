# $NetBSD: Makefile,v 1.3 2001/01/14 12:31:10 drochner Exp $
#

DISTNAME=	amaya-src-4.2.1
PKGNAME=	amaya-4.2.1
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
# our libpng is too new (png_read_init() removal)
#DEPENDS+=	png-1.0.*:../../graphics/png

USE_MOTIF=	yes
USE_GMAKE=	yes

post-extract:
	${MKDIR} ${WRKSRC}
	${RM} -rf ${WRKDIR}/Amaya/libjpeg 
	${RM} -rf ${WRKDIR}/Amaya/libpng/zlib
#	${RM} -rf ${WRKDIR}/Amaya/libpng

.include "../../mk/bsd.pkg.mk"
