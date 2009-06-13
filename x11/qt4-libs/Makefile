# $NetBSD: Makefile,v 1.28 2009/06/13 11:55:51 hasso Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../x11/qt4-libs/Makefile.common"

PKGNAME=	qt4-libs-${QTVERSION}
COMMENT=	C++ X GUI toolkit

BUILD_TARGET=		sub-src
INSTALL_TARGET=		install_flat_headers install_targ_headers

PTHREAD_OPTS+=		require
UNLIMIT_RESOURCES=	datasize
BUILDLINK_PASSTHRU_DIRS+= ${QTPREFIX}

PLIST_SRC=		${WRKDIR}/PLIST ${PKGDIR}/PLIST

# built as plugins
CONFIGURE_ARGS+=	-no-sql-sqlite
CONFIGURE_ARGS+=	-no-libtiff

INSTALLATION_DIRS=	lib/pkgconfig
INSTALLATION_DIRS+=	${QTPREFIX}/bin
INSTALLATION_DIRS+=	${QTPREFIX}/include
INSTALLATION_DIRS+=	${QTPREFIX}/lib
INSTALLATION_DIRS+=	${QTPREFIX}/plugins/accessible
INSTALLATION_DIRS+=	${QTPREFIX}/plugins/imageformats
INSTALLATION_DIRS+=	${QTPREFIX}/plugins/inputmethods

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR:Q}

do-install:
.for prog in moc rcc uic
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${prog} ${DESTDIR}${QTPREFIX}/bin/
.endfor
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/bin/uic3 \
	    ${DESTDIR}${QTPREFIX}/bin
.for incl in corelib gui network opengl qt3support sql svg xml script testlib 3rdparty/webkit/WebCore
	cd ${WRKSRC}/src/${incl} && env ${MAKE_ENV} ${INSTALL_ENV} \
		${MAKE_PROGRAM} ${INSTALL_TARGET}
.endfor
	cd ${DESTDIR}${PREFIX} && find qt4/include -type f -print > ${WRKDIR}/PLIST
.for lib in Qt3Support QtCore QtGui QtNetwork QtOpenGL QtSql QtSvg QtXml QtScript QtTest QtWebKit
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/lib/lib${lib}.la \
		${DESTDIR}${QTPREFIX}/lib/
	sed	-e "s:${WRKSRC}:${QTPREFIX}:g" \
		-e "s:${QTPREFIX}/lib/lib\([A-Za-z3]*\)\.la:-l\1:g" \
		${WRKSRC}/lib/pkgconfig/${lib}.pc > ${WRKDIR}/${lib}.pc
	${INSTALL_DATA} ${WRKDIR}/${lib}.pc ${DESTDIR}${PREFIX}/lib/pkgconfig/
.endfor
	${INSTALL_DATA} ${WRKSRC}/tools/porting/src/q3porting.xml ${DESTDIR}${QTPREFIX}
.for plug in qtaccessiblecompatwidgets qtaccessiblewidgets
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/plugins/accessible/lib${plug}.la \
		${DESTDIR}${QTPREFIX}/plugins/accessible/
.endfor
.for plug in qgif qjpeg qmng qsvg
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/plugins/imageformats/lib${plug}.la \
		${DESTDIR}${QTPREFIX}/plugins/imageformats/
.endfor
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/plugins/inputmethods/libqimsw-multi.la \
		${DESTDIR}/${QTPREFIX}/plugins/inputmethods/

.if ${OPSYS} == "Darwin" && empty(MACHINE_PLATFORM:MDarwin-[567].*)
SUBST_CLASSES+=		socklen
SUBST_MESSAGE.socklen=	Correcting socklen_t.
SUBST_STAGE.socklen=	pre-configure
SUBST_FILES.socklen=	mkspecs/darwin-g++/qplatformdefs.h
SUBST_SED.socklen=	-e 's/QT_SOCKLEN_T.*/QT_SOCKLEN_T socklen_t/'
.endif

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
