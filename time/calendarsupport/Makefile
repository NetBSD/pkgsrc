# $NetBSD: Makefile,v 1.22 2026/05/14 16:42:15 ryoon Exp $

DISTNAME=	calendarsupport-${KAPPSVER}
PKGREVISION=	4
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
