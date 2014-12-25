# $NetBSD: Makefile,v 1.10 2014/12/25 13:51:13 wiz Exp $

PKGNAME=	qt5-dbus-${QTVERSION}
PKGREVISION=	2
COMMENT=	Qt5 DBus support plugin

BUILD_DIRS=		qtbase/src/dbus
BUILD_DIRS+=		qtbase/src/tools/qdbuscpp2xml
BUILD_DIRS+=		qtbase/src/tools/qdbusxml2cpp

.include "../../x11/qt5-qtbase/Makefile.common"

CFLAGS+=		-I${BUILDLINK_PREFIX.dbus}/include/dbus-1.0
CFLAGS+=		-I${BUILDLINK_PREFIX.dbus}/lib/dbus-1.0/include/dbus
CFLAGS+=		-I${BUILDLINK_PREFIX.qt5-qtbase}/qt5/include

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

INSTALLATION_DIRS=	lib/pkgconfig

PC_FILES=		Qt5DBus.pc

post-install:
.for i in ${PC_FILES}
	${RM} -f ${DESTDIR}${PREFIX}/lib/pkgconfig/${i} && \
		cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
		${LN} -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor


.include "../../devel/gettext-lib/buildlink3.mk"
# Use lib/dbus-1.0/include/dbus/dbus-arch-deps.h from sysutils/dbus
USE_DBUS-ARCH-DEPS_H=	yes
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
