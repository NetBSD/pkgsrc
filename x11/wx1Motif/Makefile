# $NetBSD: Makefile,v 1.8 2003/12/13 20:14:27 ben Exp $
#

DISTNAME=		wx1Motif-1.68e
WRKSRC=			${WRKDIR}
CATEGORIES=		x11
MASTER_SITES=		ftp://oracle.fastpicsystems.com/pub/wxwin/1.68E/unix/
DISTFILES=		wx168_1.tgz wx168_2.tgz

MAINTAINER=		ben@netbsd.org
HOMEPAGE=		http://www.wxwindows.org/
COMMENT=		Motif-based implementation of wxWindows 1

USE_BUILDLINK2=		# defined
USE_X11=		# defined

BUILD_DIRS=		${WRKSRC}/src/x
BUILD_DIRS+=		${WRKSRC}/utils/wxhelp/src
MAKEFILE=		makefile.unx
ALL_TARGET=		motif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/utils/wxhelp/src/wxhelp_motif \
		${PREFIX}/bin/wx1help_motif
	${INSTALL_DATA_DIR} ${PREFIX}/lib/wxwindows1
	${INSTALL_DATA} ${WRKSRC}/lib/libwx_motif.a ${PREFIX}/lib/wxwindows1/
	${INSTALL_DATA_DIR} ${PREFIX}/include/wxwindows1
	${INSTALL_DATA} ${WRKSRC}/include/base/* ${WRKSRC}/include/x/* \
		${PREFIX}/include/wxwindows1

.include "../../mk/motif.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
