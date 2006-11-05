# $NetBSD: Makefile,v 1.55.2.1 2006/11/05 01:09:17 salo Exp $

PKGNAME=	qt3-libs-${QTVERSION}
MAINTAINER=	adam@NetBSD.org
COMMENT=	C++ X GUI toolkit

LIBQT=			${WRKSRC}/lib/libqt-mt.la

.include "../../mk/bsd.prefs.mk"
# XXX: hack - work round an ICE with GCC 3.3 on sparc
.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "sparc"
GCC_REQD+=		3.4
.endif

.include "../../x11/qt3-libs/Makefile.common"

.include "../../mk/compiler.mk"
.if ${OPSYS} == "Darwin" && !empty(CC_VERSION:Mgcc-4.0.0)
PKG_FAIL_REASON=	"Apple's gcc 4.0.0 yields an internal compiler error."
PKG_FAIL_REASON+=	"Please update gcc to a later version."
.endif

BUILD_TARGET=		sub-plugins

PTHREAD_OPTS+=		require

UNLIMIT_RESOURCES=	datasize

BUILDLINK_PASSTHRU_DIRS+=	${QTPREFIX}

PKGCONFIG_OVERRIDE=	lib/qt-mt.pc

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
	${INSTALL_DATA} ${WRKSRC}/lib/qt-mt.pc ${PREFIX}/lib/pkgconfig/

.if ${OPSYS} == "Darwin" && empty(MACHINE_PLATFORM:MDarwin-[567].*)
SUBST_CLASSES+=		socklen
SUBST_MESSAGE.socklen=	Correcting socklen_t.
SUBST_STAGE.socklen=	pre-configure
SUBST_FILES.socklen=	mkspecs/darwin-g++/qplatformdefs.h
SUBST_SED.socklen=	-e 's/QT_SOCKLEN_T.*/QT_SOCKLEN_T socklen_t/'
.endif

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
