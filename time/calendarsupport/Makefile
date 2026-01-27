# $NetBSD: Makefile,v 1.20 2026/01/27 08:40:42 wiz Exp $

DISTNAME=	calendarsupport-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	time

HOMEPAGE=	https://kontact.kde.org
COMMENT=	Calendar support library
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../time/akonadi-calendar/buildlink3.mk"
.include "../../time/kf6-kholidays/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
