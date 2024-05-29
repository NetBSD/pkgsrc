# $NetBSD: Makefile,v 1.14 2024/05/29 16:34:55 adam Exp $

DISTNAME=	qthttpserver-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qthttpserver-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt6 classes for creating http servers
CATEGORIES=	www
LICENSE=	gnu-gpl-v3

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6HttpServer.pc

.include "../../x11/qt6-qtbase/Makefile.common"

.include "../../net/qt6-qtwebsockets/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
