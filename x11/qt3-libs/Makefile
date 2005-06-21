# $NetBSD: Makefile,v 1.35 2005/06/21 23:06:07 jlam Exp $

LIBQT=			${WRKSRC}/lib/libqt-mt.la

.include "../qt3-libs/Makefile.common"

PKGNAME=		qt3-libs-${QTVERSION}
PKGREVISION=		2
MAINTAINER=		adam@NetBSD.org
COMMENT=		C++ X GUI toolkit

GCC_REQD+=		2.95.3

BUILD_TARGET=		sub-plugins

PTHREAD_OPTS+=		require

UNLIMIT_RESOURCES=	datasize

BUILDLINK_PASSTHRU_DIRS+= ${QTPREFIX}

do-install:
	${INSTALL_DATA_DIR} ${QTPREFIX}
	${INSTALL_PROGRAM_DIR} ${QTPREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/moc ${QTPREFIX}/bin/
	${INSTALL_LIB_DIR} ${QTPREFIX}/lib
	${LIBTOOL} ${INSTALL_LIB} ${WRKSRC}/lib/libqt-mt.la ${QTPREFIX}/lib/
	${INSTALL_DATA_DIR} ${QTPREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${QTPREFIX}/include/
	${INSTALL_DATA_DIR} ${QTPREFIX}/include/private
	${INSTALL_DATA} ${WRKSRC}/include/private/*.h ${QTPREFIX}/include/private/
	${INSTALL_LIB_DIR} ${QTPREFIX}/plugins
	${INSTALL_LIB_DIR} ${QTPREFIX}/plugins/imageformats
	${LIBTOOL} ${INSTALL_LIB} ${WRKSRC}/plugins/imageformats/libqjpeg.la ${QTPREFIX}/plugins/imageformats/
	${LIBTOOL} ${INSTALL_LIB} ${WRKSRC}/plugins/imageformats/libqmng.la ${QTPREFIX}/plugins/imageformats/

.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/Xrandr/buildlink3.mk"
.include "../../x11/xcursor/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
