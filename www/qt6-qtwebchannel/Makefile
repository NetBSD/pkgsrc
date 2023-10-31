# $NetBSD: Makefile,v 1.8 2023/10/31 19:56:51 adam Exp $

DISTNAME=	qtwebchannel-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtwebchannel-${QTVERSION}
COMMENT=	Qt6 webchannel module
CATEGORIES=	www
LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2 OR gnu-gpl-v3

.include "../../x11/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6WebChannel.pc

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../net/qt6-qtwebsockets/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
