# $NetBSD: Makefile,v 1.8 2016/03/02 23:03:59 ryoon Exp $

DISTNAME=	qt5-${QTVERSION}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	# none

COMMENT=	"meta-package" for version 5 of the QT GUI C++ toolkit

META_PACKAGE=	yes

.include "Makefile.common"

DEPENDS+=	qt5-mysql-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-mysql
DEPENDS+=	qt5-odbc-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-odbc
DEPENDS+=	qt5-psql-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-psql
DEPENDS+=	qt5-qtbase-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtbase
DEPENDS+=	qt5-qtdeclarative-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtdeclarative
DEPENDS+=	qt5-qtdoc-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtdoc
DEPENDS+=	qt5-qtgraphicaleffects-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtgraphicaleffects
DEPENDS+=	qt5-qtimageformats-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtimageformats
DEPENDS+=	qt5-qtlocation-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtlocation
DEPENDS+=	qt5-qtmultimedia-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtmultimedia
DEPENDS+=	qt5-qtquick1-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtquick1
DEPENDS+=	qt5-qtquickcontrols-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtquickcontrols
DEPENDS+=	qt5-qtscript-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtscript
DEPENDS+=	qt5-qtsensors-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtsensors
DEPENDS+=	qt5-qtserialport-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtserialport
DEPENDS+=	qt5-qtsvg-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtsvg
DEPENDS+=	qt5-qttools-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qttools
DEPENDS+=	qt5-qttranslations-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qttranslations
DEPENDS+=	qt5-qtwebchannel-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtwebchannel
DEPENDS+=	qt5-qtwebkit-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtwebkit
DEPENDS+=	qt5-websockets-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtwebsockets
DEPENDS+=	qt5-qtxmlpatterns-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtxmlpatterns
DEPENDS+=	qt5-sqlite3-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-sqlite3
.if ${OPSYS} == "Darwin"
DEPENDS+=	qt5-qtmacextras-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtmacextras
.else
DEPENDS+=	qt5-qtx11extras-${QTVERSION}{,nb[0-9]*}:../../x11/qt5-qtx11extras
.endif

.include "../../mk/bsd.pkg.mk"
