# $NetBSD: Makefile,v 1.24 2004/04/16 14:30:44 recht Exp $
#

LIBQT=			${WRKSRC}/lib/libqt-mt.la

.include "../qt3-libs/Makefile.common"

PKGNAME=		qt3-libs-${QTVERSION}
COMMENT=		C++ X GUI toolkit

USE_BUILDLINK2=		yes
GCC_REQD+=		2.95.3

ALL_TARGET=		sub-plugins

PTHREAD_OPTS+=		require

UNLIMIT_RESOURCES=	datasize

BUILDLINK_PASSTHRU_DIRS+= ${QTPREFIX}

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

.include "../../devel/zlib/buildlink2.mk"
.include "../../fonts/Xft2/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../graphics/mng/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../x11/Xrandr/buildlink2.mk"
.include "../../x11/xcursor/buildlink2.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
