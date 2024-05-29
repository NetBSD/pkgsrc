# $NetBSD: Makefile,v 1.14 2024/05/29 16:34:55 adam Exp $

DISTNAME=	qtwebchannel-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtwebchannel-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt6 webchannel module
CATEGORIES=	www
LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2 OR gnu-gpl-v3

.include "../../x11/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6WebChannel.pc

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../net/qt6-qtwebsockets/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
