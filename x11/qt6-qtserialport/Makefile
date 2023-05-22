# $NetBSD: Makefile,v 1.4 2023/05/22 21:00:15 wiz Exp $

DISTNAME=	qtserialport-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtserialport-${QTVERSION}
PKGREVISION=	2
CATEGORIES=	x11 comms
COMMENT=	Qt6 module for Serial Port
LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2 OR gnu-gpl-v3

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6SerialPort.pc

.include "../../x11/qt6-qtbase/Makefile.common"

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
