# $NetBSD: Makefile,v 1.33 2001/10/24 22:11:10 jlam Exp $
# FreeBSD Id: Makefile,v 1.15 1998/05/27 08:44:56 dburr Exp
#

DISTNAME=		Mosaic-src-2.7b5
PKGNAME=		mosaic-2.7b5
WRKSRC=			${WRKDIR}/Mosaic-src
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.ncsa.uiuc.edu/Web/Mosaic/Unix/source/

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://www.ncsa.uiuc.edu/SDG/Software/Mosaic/
COMMENT=		World Wide Web browser

LICENSE=		mosaic-license

NOT_FOR_PLATFORM=	*-*-alpha	#LP64 problems

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES
USE_MOTIF12=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-jpegdir=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-pngdir=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-zdir=${BUILDLINK_DIR}

CPPFLAGS+=		-Dunix

post-configure:
	@${ECHO} '' >>${WRKSRC}/config.h
	@${ECHO} '#define PREFIX "${PREFIX}"' >>${WRKSRC}/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/Mosaic ${PREFIX}/bin
	${LN} -sf Mosaic ${PREFIX}/bin/mosaic
	${INSTALL_DATA} ${WRKSRC}/app-defaults.color \
		${PREFIX}/lib/X11/app-defaults/Mosaic
	${INSTALL_DATA_DIR} ${PREFIX}/share/mosaic

.include "../../devel/zlib/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/motif.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
