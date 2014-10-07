# $NetBSD: Makefile,v 1.18 2014/10/07 16:47:17 adam Exp $

PKGNAME=	qt5-qtwebkit-${QTVERSION}
PKGREVISION=	4
COMMENT=	Qt5 WebView module

.include "../../x11/qt5-qtbase/Makefile.common"

BUILD_DEPENDS+=		gperf-[0-9]*:../../devel/gperf

USE_LIBTOOL=		yes
USE_TOOLS+=		bison flex pkg-config sed

BUILD_DIRS=		qtwebkit
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

BUILDLINK_TRANSFORM+=	rpath:${WRKSRC}/qtwebkit/lib:${QTDIR}/lib
QTPKGCONFIGPC=		Qt5WebKit.pc Qt5WebKitWidgets.pc

BROKEN_FILES+=		qt5/lib/pkgconfig/Qt5WebKit.pc \
			qt5/lib/libQt5WebKit.la \
			qt5/lib/libQt5WebKitWidgets.la \
			qt5/qml/QtWebKit/experimental/libqmlwebkitexperimentalplugin.la \
			qt5/qml/QtWebKit/libqmlwebkitplugin.la

post-install:
# Fix broken files
.for i in ${BROKEN_FILES}
	${CP} -f ${DESTDIR}${PREFIX}/${i} \
		${DESTDIR}${PREFIX}/${i}.1
	${SED} -e 's,${WRKSRC}/[^[:space:]]*,,g' \
		< ${DESTDIR}${PREFIX}/${i}.1 \
		| ${SED} -e 's/-lWebKit1 //' \
		| ${SED} -e 's/-lWebKit2 //' \
		| ${SED} -e 's/-lWebCore //' \
		| ${SED} -e 's/-lANGLE //' \
		| ${SED} -e 's/-lJavaScriptCore //' \
		| ${SED} -e 's/-lWTF //' \
		> ${DESTDIR}${PREFIX}/${i}
	${RM} -f ${DESTDIR}${PREFIX}/${i}.1
.endfor
.for i in ${QTPKGCONFIGPC}
	${RM} -f ${DESTDIR}${PREFIX}/lib/pkgconfig/${i} && \
		cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
		ln -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../databases/sqlite3/buildlink3.mk"
.if ${OPSYS} == "Darwin" || ${OPSYS} == "Linux" || ${OPSYS} == "NetBSD"
.include "../../devel/libexecinfo/buildlink3.mk"
.endif
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.endif
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtlocation/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtsensors/buildlink3.mk"
PYTHON_FOR_BUILD_ONLY=			yes
.include "../../lang/python/tool.mk"
.include "../../lang/ruby/buildlink3.mk"
BUILDLINK_DEPMETHOD.${RUBY_BASE}=	build
.include "../../mk/bsd.pkg.mk"
