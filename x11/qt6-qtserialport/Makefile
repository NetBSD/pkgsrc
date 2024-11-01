# $NetBSD: Makefile,v 1.15 2024/11/01 00:54:29 wiz Exp $

DISTNAME=	qtserialport-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtserialport-${QTVERSION}
PKGREVISION=	1
CATEGORIES=	x11 comms
COMMENT=	Qt6 module for Serial Port
LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2 OR gnu-gpl-v3

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6SerialPort.pc

.include "../../x11/qt6-qtbase/Makefile.common"

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
