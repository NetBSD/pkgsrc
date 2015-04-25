# $NetBSD: Makefile,v 1.13 2015/04/25 14:25:17 tnn Exp $

DISTNAME=	qtbase-opensource-src-${QTVERSION}
PKGNAME=	qt5-dbus-${QTVERSION}
PKGREVISION=	2
COMMENT=	Qt5 DBus support plugin

BUILD_DIRS=		src/dbus
BUILD_DIRS+=		src/tools/qdbuscpp2xml
BUILD_DIRS+=		src/tools/qdbusxml2cpp

.include "../../x11/qt5-qtbase/Makefile.common"

CFLAGS+=		-I${BUILDLINK_PREFIX.dbus}/include/dbus-1.0
CFLAGS+=		-I${BUILDLINK_PREFIX.dbus}/lib/dbus-1.0/include/dbus
CFLAGS+=		-I${BUILDLINK_PREFIX.qt5-qtbase}/qt5/include

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS=	lib/pkgconfig

do-configure:
	${RM} -f -r ${WRKSRC}/mkspecs
.for d in ${BUILD_DIRS}
	cd ${WRKSRC}/${d} && ${QTPREFIX}/bin/qmake -o Makefile
.endfor

post-install:
.for i in Qt5DBus.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	${LN} -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
# Use lib/dbus-1.0/include/dbus/dbus-arch-deps.h from sysutils/dbus
USE_DBUS-ARCH-DEPS_H=	yes
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
