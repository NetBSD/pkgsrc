# $NetBSD: Makefile,v 1.1.1.1 2006/02/20 12:08:15 adam Exp $

.include "../../x11/qt4-libs/Makefile.common"

PKGNAME=		qt4-libs-${QTVERSION}
COMMENT=		C++ X GUI toolkit

BUILD_TARGET=		sub-src
PTHREAD_OPTS+=		require
UNLIMIT_RESOURCES=	datasize
BUILDLINK_PASSTHRU_DIRS+= ${QTPREFIX}

do-install:
	${INSTALL_DATA_DIR} ${QTPREFIX}
	${INSTALL_PROGRAM_DIR} ${QTPREFIX}/bin
.for prog in moc rcc uic
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${prog} ${QTPREFIX}/bin/
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/bin/uic3 ${QTPREFIX}/bin/
	${INSTALL_DATA_DIR} ${QTPREFIX}/include
.for inc in Qt Qt3Support QtCore QtGui QtNetwork QtOpenGL QtSql QtSvg QtXml
	${INSTALL_DATA_DIR} ${QTPREFIX}/include/${inc}
	${INSTALL_DATA} ${WRKSRC}/include/${inc}/q*.h ${QTPREFIX}/include/${inc}/
.endfor
	${INSTALL_LIB_DIR} ${QTPREFIX}/lib
.for lib in Qt3Support QtCore QtGui QtNetwork QtOpenGL QtSql QtSvg QtXml
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/lib/lib${lib}.la \
		${QTPREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/lib/${lib}.pc ${PREFIX}/lib/pkgconfig/
.endfor
	${INSTALL_LIB_DIR} ${QTPREFIX}/plugins
	${INSTALL_LIB_DIR} ${QTPREFIX}/plugins/accessible
.for plug in qtaccessiblecompatwidgets qtaccessiblewidgets
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/plugins/accessible/lib${plug}.la \
		${QTPREFIX}/plugins/accessible/
.endfor
	${INSTALL_LIB_DIR} ${QTPREFIX}/plugins/codecs
.for plug in qcncodecs qjpcodecs qkrcodecs qtwcodecs
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/plugins/codecs/lib${plug}.la \
		${QTPREFIX}/plugins/codecs/
.endfor
	${INSTALL_LIB_DIR} ${QTPREFIX}/plugins/imageformats/
.for plug in qgif qjpeg qmng
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/plugins/imageformats/lib${plug}.la \
		${QTPREFIX}/plugins/imageformats/
.endfor

.if ${OPSYS} == "Darwin" && empty(MACHINE_PLATFORM:MDarwin-[567].*)
SUBST_CLASSES+=		socklen
SUBST_MESSAGE.socklen=	Correcting socklen_t.
SUBST_STAGE.socklen=	pre-configure
SUBST_FILES.socklen=	mkspecs/darwin-g++/qplatformdefs.h
SUBST_SED.socklen=	-e 's/QT_SOCKLEN_T.*/QT_SOCKLEN_T socklen_t/'
.endif

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/Xrandr/buildlink3.mk"
.include "../../x11/xcursor/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
