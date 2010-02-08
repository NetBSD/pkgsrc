# $NetBSD: Makefile,v 1.44 2010/02/08 10:49:07 wiz Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../x11/qt4-libs/Makefile.common"

PKGNAME=	qt4-libs-${QTVERSION}
PKGREVISION=	4
COMMENT=	C++ X GUI toolkit

# XXX this is to test what really gets installed when 'do-install' is disabled
INSTALL_DIRS+=		src

BUILD_TARGET=		sub-src

PTHREAD_OPTS+=		require
UNLIMIT_RESOURCES=	datasize
BUILDLINK_PASSTHRU_DIRS+=${QTPREFIX}

PLIST_SRC=		${WRKDIR}/PLIST ${PKGDIR}/PLIST

# built as plugins
CONFIGURE_ARGS+=	-no-dbus
CONFIGURE_ARGS+=	-no-libmng
CONFIGURE_ARGS+=	-no-libtiff
CONFIGURE_ARGS+=	-no-sql-sqlite

INSTALLATION_DIRS=	lib/pkgconfig
INSTALLATION_DIRS+=	${QTPREFIX}/bin
INSTALLATION_DIRS+=	${QTPREFIX}/include
INSTALLATION_DIRS+=	${QTPREFIX}/lib
INSTALLATION_DIRS+=	${QTPREFIX}/plugins/accessible
INSTALLATION_DIRS+=	${QTPREFIX}/plugins/codecs
INSTALLATION_DIRS+=	${QTPREFIX}/plugins/graphicssystems
INSTALLATION_DIRS+=	${QTPREFIX}/plugins/iconengines
INSTALLATION_DIRS+=	${QTPREFIX}/plugins/imageformats
INSTALLATION_DIRS+=	${QTPREFIX}/plugins/inputmethods

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

do-install:
.for prog in moc rcc uic
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${prog} ${DESTDIR}${QTPREFIX}/bin/
.endfor
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/bin/uic3 \
	    ${DESTDIR}${QTPREFIX}/bin
.for incl in corelib gui multimedia network opengl qt3support script scripttools sql svg testlib xml xmlpatterns 3rdparty/webkit/WebCore
	cd ${WRKSRC}/src/${incl} && env ${MAKE_ENV} ${INSTALL_ENV} \
		${MAKE_PROGRAM} install_flat_headers install_targ_headers install_class_headers
.endfor
	cd ${DESTDIR}${PREFIX} && find qt4/include -type f -print > ${WRKDIR}/PLIST
.for lib in Qt3Support QtCore QtGui QtMultimedia QtNetwork QtOpenGL QtSql QtSvg QtXml QtXmlPatterns QtScript QtScriptTools QtTest QtWebKit
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/lib/lib${lib}.la \
		${DESTDIR}${QTPREFIX}/lib/
	sed	-e "s:${WRKSRC}:${QTPREFIX}:g" \
		-e "s:${QTPREFIX}/lib/lib\\([A-Za-z3]*\\)\\.la:-l\\1:g" \
		${WRKSRC}/lib/pkgconfig/${lib}.pc > ${WRKDIR}/${lib}.pc
	${INSTALL_DATA} ${WRKDIR}/${lib}.pc ${DESTDIR}${PREFIX}/lib/pkgconfig/
.endfor
	${INSTALL_DATA} ${WRKSRC}/tools/porting/src/q3porting.xml ${DESTDIR}${QTPREFIX}
.for plug in qtaccessiblecompatwidgets qtaccessiblewidgets
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/plugins/accessible/lib${plug}.la \
		${DESTDIR}${QTPREFIX}/plugins/accessible/
.endfor
.for codec in qcncodecs qjpcodecs qkrcodecs qtwcodecs
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/plugins/codecs/lib${codec}.la \
		${DESTDIR}${QTPREFIX}/plugins/codecs/
.endfor
.for gfxs in qglgraphicssystem qtracegraphicssystem
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/plugins/graphicssystems/lib${gfxs}.la \
		${DESTDIR}${QTPREFIX}/plugins/graphicssystems/
.endfor
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/plugins/iconengines/libqsvgicon.la \
		${DESTDIR}/${QTPREFIX}/plugins/iconengines/
.for plug in qgif qico qjpeg qsvg
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
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
