# $NetBSD: Makefile,v 1.49 2020/11/05 09:07:21 ryoon Exp $

DISTNAME=	qtsensors-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtsensors-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt5 module for Sensors

BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5Sensors.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	${LN} -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

PLIST_VARS+=		dbus
.include "../../x11/qt5-qtbase/buildlink3.mk"
.if ${PKG_BUILD_OPTIONS.qt5-qtbase:Mdbus}
PLIST.dbus=		yes
.endif

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
