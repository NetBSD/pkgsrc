# $NetBSD: Makefile,v 1.8 2002/08/08 16:17:08 jlam Exp $
#

.include "../qt3-libs/Makefile.common"

PKGNAME=		qt3-libs-${QTVERSION}
PKGREVISION=		2
COMMENT=		C++ X GUI toolkit

USE_BUILDLINK_ONLY=	yes
BUILDLINK_QTDIR=	${WRKSRC}

MAKE_ENV+=		LIBQT="${WRKSRC}/lib/libqt-mt.la"

ALL_TARGET=		sub-plugins

PTHREAD_OPTS+=		require

UNLIMIT_RESOURCES=	datasize

post-extract:
	${RM} -f ${WRKSRC}/include/qt_windows.h

do-install:
	${INSTALL_DATA_DIR} ${QTPREFIX}
	${INSTALL_PROGRAM_DIR} ${QTPREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/moc ${QTPREFIX}/bin
	${INSTALL_DATA_DIR} ${QTPREFIX}/lib
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/lib/libqt-mt.la ${QTPREFIX}/lib
	${INSTALL_DATA_DIR} ${QTPREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${QTPREFIX}/include
	${INSTALL_DATA_DIR} ${QTPREFIX}/include/private
	${INSTALL_DATA} ${WRKSRC}/include/private/*.h ${QTPREFIX}/include/private
	${INSTALL_DATA_DIR} ${QTPREFIX}/plugins
	${INSTALL_DATA_DIR} ${QTPREFIX}/plugins/imageformats
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/plugins/imageformats/libqjpeg.la ${QTPREFIX}/plugins/imageformats
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/plugins/imageformats/libqmng.la ${QTPREFIX}/plugins/imageformats

.include "../../devel/zlib/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/Mesa/buildlink.mk"
.include "../../graphics/mng/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/freetype2/buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
