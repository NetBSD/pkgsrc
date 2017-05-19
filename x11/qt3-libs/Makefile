# $NetBSD: Makefile,v 1.96 2017/05/19 13:29:05 prlw1 Exp $

PKGNAME=	qt3-libs-${QTVERSION}
PKGREVISION=	31
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
PKG_FAIL_REASON+=	"Apple's gcc 4.0.0 yields an internal compiler error."
PKG_FAIL_REASON+=	"Please update gcc to a later version."
.endif

BUILD_TARGET=		sub-plugins

PTHREAD_OPTS+=		require

UNLIMIT_RESOURCES=	datasize

BUILDLINK_PASSTHRU_DIRS+=	${QTPREFIX}

INSTALLATION_DIRS=	${QTPREFIX}/bin ${QTPREFIX}/include/private
INSTALLATION_DIRS+=	${QTPREFIX}/lib ${QTPREFIX}/plugins/imageformats
INSTALLATION_DIRS+=	lib/pkgconfig

PKGCONFIG_OVERRIDE=	lib/qt-mt.pc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/moc ${DESTDIR}${QTPREFIX}/bin
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/lib/libqt-mt.la ${DESTDIR}${QTPREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${DESTDIR}${QTPREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/private/*.h ${DESTDIR}${QTPREFIX}/include/private
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/plugins/imageformats/libqjpeg.la ${DESTDIR}${QTPREFIX}/plugins/imageformats/
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/plugins/imageformats/libqmng.la ${DESTDIR}${QTPREFIX}/plugins/imageformats/
	${INSTALL_DATA} ${WRKSRC}/lib/qt-mt.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

.if ${OPSYS} == "Darwin" && empty(MACHINE_PLATFORM:MDarwin-[567].*)
SUBST_CLASSES+=		socklen
SUBST_MESSAGE.socklen=	Correcting socklen_t.
SUBST_STAGE.socklen=	pre-configure
SUBST_FILES.socklen=	mkspecs/darwin-g++/qplatformdefs.h
SUBST_SED.socklen=	-e 's/QT_SOCKLEN_T.*/QT_SOCKLEN_T socklen_t/'
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
BUILDLINK_API_DEPENDS.png+=	png>=1.5.1
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
