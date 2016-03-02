# $NetBSD: Makefile,v 1.31 2016/03/02 23:04:01 ryoon Exp $

DISTNAME=	qtwebkit-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtwebkit-${QTVERSION}
PKGREVISION=	2
COMMENT=	Qt5 WebView module

BUILD_DEPENDS+=		gperf-[0-9]*:../../devel/gperf

USE_TOOLS+=		bison flex pkg-config sed
REPLACE_PERL+=		Source/WebKit2/Scripts/generate-forwarding-headers.pl

MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

.if ${USE_CWRAPPERS:Uno} == "yes"
BUILDLINK_TRANSFORM+=	R:${WRKSRC}/lib:${QTDIR}/lib
.else
BUILDLINK_TRANSFORM+=	rpath:${WRKSRC}/lib:${QTDIR}/lib
.endif

.if ${OPSYS} == "NetBSD" && ${MACHINE_CPU:U} == "arm"
LDFLAGS+=	-Wl,-no-keep-memory -Wl-reduce-memory
.endif

post-install:
.for i in Qt5WebKit.pc Qt5WebKitWidgets.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	ln -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../databases/sqlite3/buildlink3.mk"
.if ${OPSYS} == "Darwin" || ${OPSYS} == "Linux" || ${OPSYS} == "NetBSD"
.include "../../devel/libexecinfo/buildlink3.mk"
.endif
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.endif
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtlocation/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtsensors/buildlink3.mk"
.include "../../x11/qt5-qtwebchannel/buildlink3.mk"
PYTHON_FOR_BUILD_ONLY=			yes
.include "../../lang/python/tool.mk"
.include "../../lang/ruby/buildlink3.mk"
BUILDLINK_DEPMETHOD.${RUBY_BASE}=	build
.include "../../mk/bsd.pkg.mk"
