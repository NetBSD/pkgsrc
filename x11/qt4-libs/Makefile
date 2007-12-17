# $NetBSD: Makefile,v 1.20 2007/12/17 22:19:43 adam Exp $

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

do-install:
	${INSTALL_DATA_DIR} ${QTPREFIX}
	${INSTALL_PROGRAM_DIR} ${QTPREFIX}/bin
.for prog in moc rcc uic
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${prog} ${QTPREFIX}/bin/
.endfor
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/bin/uic3 \
	    ${QTPREFIX}/bin
	${INSTALL_DATA_DIR} ${QTPREFIX}/include
.for incl in corelib gui network opengl qt3support sql svg xml script
	cd ${WRKSRC}/src/${incl} && env ${MAKE_ENV} \
		${MAKE_PROGRAM} ${INSTALL_TARGET}
.endfor
	cd ${PREFIX} && find qt4/include -type f -print > ${WRKDIR}/PLIST
	${INSTALL_LIB_DIR} ${QTPREFIX}/lib
.for lib in Qt3Support QtCore QtGui QtNetwork QtOpenGL QtSql QtSvg QtXml QtScript
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/lib/lib${lib}.la \
		${QTPREFIX}/lib/
	sed	-e "s:${WRKSRC}:${QTPREFIX}:g" \
		-e "s:${QTPREFIX}/lib/lib\([A-Za-z3]*\)\.la:-l\1:g" \
		${WRKSRC}/lib/pkgconfig/${lib}.pc > ${WRKDIR}/${lib}.pc
	${INSTALL_DATA} ${WRKDIR}/${lib}.pc ${PREFIX}/lib/pkgconfig/
.endfor
	${INSTALL_DATA} ${WRKSRC}/tools/porting/src/q3porting.xml ${QTPREFIX}
	${INSTALL_LIB_DIR} ${QTPREFIX}/plugins
	${INSTALL_LIB_DIR} ${QTPREFIX}/plugins/accessible
.for plug in qtaccessiblecompatwidgets qtaccessiblewidgets
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/plugins/accessible/lib${plug}.la \
		${QTPREFIX}/plugins/accessible/
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
