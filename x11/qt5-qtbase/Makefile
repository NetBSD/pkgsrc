# $NetBSD: Makefile,v 1.6 2014/02/12 23:18:55 tron Exp $

PKGNAME=	qt5-qtbase-${QTVERSION}
PKGREVISION=	5
COMMENT=	C++ X GUI toolkit

.include "../../x11/qt5-qtbase/Makefile.common"

BUILD_DIRS+=		qtbase

PTHREAD_OPTS+=		require
UNLIMIT_RESOURCES=	datasize

BUILDLINK_PASSTHRU_DIRS+=	${QTPREFIX}

# kdelibs4 requires openssl support!
CONFIGURE_ARGS+=	-openssl-linked

INSTALLATION_DIRS=	${QTPREFIX}/bin lib/pkgconfig

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

CHECK_INTERPRETER_SKIP+=	qt5/examples/widgets/tools/echoplugin/echoplugin.pro
CHECK_INTERPRETER_SKIP+=	qt5/examples/widgets/tools/echoplugin/plugin/plugin.pro
CHECK_INTERPRETER_SKIP+=	qt5/examples/widgets/tools/plugandpaint/plugandpaint.pro
CHECK_INTERPRETER_SKIP+=	qt5/examples/widgets/tools/plugandpaintplugins/basictools/basictools.pro
CHECK_INTERPRETER_SKIP+=	qt5/examples/widgets/tools/plugandpaintplugins/extrafilters/extrafilters.pro
CHECK_INTERPRETER_SKIP+=	qt5/examples/widgets/tools/styleplugin/plugin/plugin.pro

BROKEN_FILES=		qt5/mkspecs/modules/qt_lib_bootstrap_private.pri

PC_FILES=		Qt5Bootstrap.pc Qt5Concurrent.pc Qt5Core.pc \
			Qt5Gui.pc Qt5Network.pc Qt5OpenGL.pc \
			Qt5OpenGLExtensions.pc Qt5PlatformSupport.pc \
			Qt5PrintSupport.pc Qt5Sql.pc Qt5Test.pc \
			Qt5Widgets.pc Qt5Xml.pc

#pre-configure: remove-3rdparty-libs set-qmake-conf

post-configure:
	cd ${WRKSRC}/${BUILD_DIRS} && ./bin/qmake -o Makefile

post-install:
.for prog in moc qdoc rcc uic
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/qtbase/bin/${prog} \
		${DESTDIR}${QTPREFIX}/bin/
.endfor
.for i in ${PC_FILES}
	${RM} -f ${DESTDIR}${PREFIX}/lib/pkgconfig/${i} && \
		cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
		ln -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor
	cd ${WRKSRC}/qtbase && env ${MAKE_ENV} ${INSTALL_ENV} \
		${MAKE_PROGRAM} install_mkspecs
	${CP} ${DESTDIR}${PREFIX}/${BROKEN_FILES} \
		${DESTDIR}${PREFIX}/${BROKEN_FILES}.1
# The pri file has WRKSRC in it.
	${SED} -e 's,${WRKSRC}/qtbase/bin/qmake,${QTDIR}/bin/qmake,g' \
		< ${DESTDIR}${PREFIX}/${BROKEN_FILES}.1 \
		> ${DESTDIR}${PREFIX}/${BROKEN_FILES}
	${RM} -f ${DESTDIR}${PREFIX}/${BROKEN_FILES}.1

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
