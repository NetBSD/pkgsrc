# $NetBSD: Makefile,v 1.3.2.3 2002/06/23 19:06:45 jlam Exp $
#

PKGNAME=		qt3-libs-${QTVERSION}
PKGREVISION=		1
COMMENT=		C++ X GUI toolkit

USE_BUILDLINK2=		yes

MAKE_ENV+=		LIBQT="${WRKSRC}/lib/libqt-mt.la"

ALL_TARGET=		sub-plugins

USE_PTHREAD=		native pth-syscall

.include "../../mk/bsd.prefs.mk"

UNLIMIT_RESOURCES=	datasize

post-extract:
	${RM} -f ${WRKSRC}/include/qt_windows.h

do-install:
	${INSTALL_DATA_DIR} ${QTPREFIX}
	${INSTALL_PROGRAM_DIR} ${QTPREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/moc ${QTPREFIX}/bin
	${INSTALL_DATA_DIR} ${QTPREFIX}/lib
	${PKGLIBTOOL} ${INSTALL_DATA} ${WRKSRC}/lib/libqt-mt.la ${QTPREFIX}/lib
	${INSTALL_DATA_DIR} ${QTPREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${QTPREFIX}/include
	${INSTALL_DATA_DIR} ${QTPREFIX}/include/private
	${INSTALL_DATA} ${WRKSRC}/include/private/*.h ${QTPREFIX}/include/private
	${INSTALL_DATA_DIR} ${QTPREFIX}/plugins
	${INSTALL_DATA_DIR} ${QTPREFIX}/plugins/imageformats
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/plugins/imageformats/libqjpeg.la ${QTPREFIX}/plugins/imageformats
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/plugins/imageformats/libqmng.la ${QTPREFIX}/plugins/imageformats

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/Mesa/buildlink2.mk"
.include "../../graphics/mng/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
