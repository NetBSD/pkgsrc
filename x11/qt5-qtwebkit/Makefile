# $NetBSD: Makefile,v 1.3 2013/12/15 00:09:22 wiz Exp $

PKGNAME=	qt5-qtwebkit-${QTVERSION}
COMMENT=	Qt5 WebView module

.include "../../x11/qt5-qtbase/Makefile.common"

BUILD_DEPENDS+=		gperf-[0-9]*:../../devel/gperf

USE_LIBTOOL=		yes

BUILD_DIRS+=		qtwebkit
MAKE_ENV+=		QTDIR=${QTDIR}

USE_TOOLS+=		bison sed pkg-config

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

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
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtlocation/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtsensors/buildlink3.mk"
.include "../../lang/python/tool.mk"
BUILDLINK_DEPMETHOD.ruby=	build
.include "../../lang/ruby/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
