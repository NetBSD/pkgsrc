# $NetBSD: Makefile,v 1.1.1.1 2002/06/17 02:24:56 dmcmahill Exp $
#

DISTNAME=		wx1Motif-1.68e
CATEGORIES=		x11
MASTER_SITES=		ftp://oracle.fastpicsystems.com/pub/wxwin/1.68E/unix/
DISTFILES=		wx168_1.tgz wx168_2.tgz

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://www.wxwindows.org
COMMENT=		Motif-based implementation of wxWindows 1

WRKSRC=			${WRKDIR}
USE_BUILDLINK_ONLY=	# defined

do-build:
	cd ${WRKSRC}/src/x && ${MAKE_ENV} ${MAKE_PROGRAM} -f makefile.unx motif
	cd ${WRKSRC}/utils/wxhelp/src && ${MAKE_ENV} ${MAKE_PROGRAM} -f makefile.unx motif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/utils/wxhelp/src/wxhelp_motif \
		${PREFIX}/bin/wx1help_motif
	${INSTALL_DATA_DIR} ${PREFIX}/lib/wxwindows1
	${INSTALL_DATA} ${WRKSRC}/lib/libwx_motif.a ${PREFIX}/lib/wxwindows1/
	${INSTALL_DATA_DIR} ${PREFIX}/include/wxwindows1
	${INSTALL_DATA} ${WRKSRC}/include/base/* ${WRKSRC}/include/x/* \
		${PREFIX}/include/wxwindows1

.include "../../mk/motif.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
