# $NetBSD: Makefile,v 1.20 2022/03/26 20:37:09 tnn Exp $

DISTNAME=	qt5-${QTVERSION}

COMMENT=	"meta-package" for version 5 of the QT GUI C++ toolkit

META_PACKAGE=	yes

.include "Makefile.common"

DEPENDS+=	qt5-qtbase-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtbase
DEPENDS+=	qt5-qtcharts-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtcharts
DEPENDS+=	qt5-qtconnectivity-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtconnectivity
DEPENDS+=	qt5-qtdeclarative-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtdeclarative
DEPENDS+=	qt5-qtdoc-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtdoc
DEPENDS+=	qt5-qtgraphicaleffects-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtgraphicaleffects
DEPENDS+=	qt5-qtimageformats-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtimageformats
DEPENDS+=	qt5-qtlocation-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtlocation
DEPENDS+=	qt5-qtmultimedia-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtmultimedia
DEPENDS+=	qt5-qtnetworkauth-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtnetworkauth
DEPENDS+=	qt5-qtquickcontrols-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtquickcontrols
DEPENDS+=	qt5-qtquickcontrols2-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtquickcontrols2
DEPENDS+=	qt5-qtscript-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtscript
DEPENDS+=	qt5-qtscxml-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtscxml
DEPENDS+=	qt5-qtsensors-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtsensors
DEPENDS+=	qt5-qtserialport-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtserialport
DEPENDS+=	qt5-qtspeech-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtspeech
DEPENDS+=	qt5-qtsvg-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtsvg
DEPENDS+=	qt5-qttools-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qttools
DEPENDS+=	qt5-qttranslations-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qttranslations
DEPENDS+=	qt5-qtvirtualkeyboard-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtvirtualkeyboard
DEPENDS+=	qt5-qtwebchannel-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtwebchannel
DEPENDS+=	qt5-qtwebsockets-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtwebsockets
DEPENDS+=	qt5-qtxmlpatterns-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtxmlpatterns
.if ${OPSYS} == "Darwin"
DEPENDS+=	qt5-qtmacextras-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtmacextras
.else
DEPENDS+=	qt5-qtx11extras-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtx11extras
.endif
.include "../../devel/wayland/platform.mk"
.if ${PLATFORM_SUPPORTS_WAYLAND} == "yes"
DEPENDS+=	qt5-qtwayland-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtwayland
.endif

.include "../../mk/bsd.pkg.mk"
