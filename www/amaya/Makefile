# $NetBSD: Makefile,v 1.9 2001/06/29 15:01:35 zuntum Exp $

DISTNAME=	amaya-src-4.3.2
PKGNAME=	amaya-4.3.2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.w3.org/pub/amaya/
EXTRACT_SUFX=	.tgz

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://www.w3.org/Amaya/
COMMENT=	Web Browser/Editor from the World Wide Web Consortium

USE_BUILDLINK_ONLY=	YES
WRKSRC=		${WRKDIR}/Amaya/work
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS+=	--with-motif --without-graphic-libs
CONFIGURE_ENV+=	MOTIFBASE=${MOTIFBASE}
CFLAGS+=	-Dunix

USE_MOTIF=	yes
USE_GMAKE=	yes

post-extract:
	${MKDIR} ${WRKSRC}
	${RM} -rf ${WRKDIR}/Amaya/libjpeg
	${RM} -rf ${WRKDIR}/Amaya/libpng/zlib
	${RM} -rf ${WRKDIR}/Amaya/libpng

.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
