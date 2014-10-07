# $NetBSD: Makefile,v 1.9 2014/10/07 16:47:16 adam Exp $

PKGNAME=	qt5-dbus-${QTVERSION}
PKGREVISION=	2
COMMENT=	Qt5 DBus support plugin

.include "../../x11/qt5-qtbase/Makefile.common"

BUILD_DIRS=		qtbase/src/dbus

CFLAGS+=		-I${BUILDLINK_PREFIX.dbus}/include/dbus-1.0
CFLAGS+=		-I${BUILDLINK_PREFIX.dbus}/lib/dbus-1.0/include/dbus
CFLAGS+=		-I${BUILDLINK_PREFIX.qt5-qtbase}/qt5/include

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

INSTALLATION_DIRS=	${QTPREFIX}/bin lib/pkgconfig

PC_FILES=		Qt5DBus.pc

# XXX: this is an ugly hack
# qdbuscpp2xml and qdbusxml2cpp should be built and installed, because
# they are referenced from Qt5DBusConfigExtras.cmake, and cmake
# fails to find qtdbus if they are not installed
# I didn't manage to build them though, and the only customers so far
# didn't need their functionality -- wiz 20140501
post-build:
	${ECHO} '#!/bin/sh' > ${WRKSRC}/dummy
	${ECHO} 'false' >> ${WRKSRC}/dummy

post-install:
.for i in ${PC_FILES}
	${RM} -f ${DESTDIR}${PREFIX}/lib/pkgconfig/${i} && \
		cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
		${LN} -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/dummy ${DESTDIR}${PREFIX}/qt5/bin/qdbuscpp2xml
	${INSTALL_SCRIPT} ${WRKSRC}/dummy ${DESTDIR}${PREFIX}/qt5/bin/qdbusxml2cpp

.include "../../devel/gettext-lib/buildlink3.mk"
# Use lib/dbus-1.0/include/dbus/dbus-arch-deps.h from sysutils/dbus
USE_DBUS-ARCH-DEPS_H=	yes
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
