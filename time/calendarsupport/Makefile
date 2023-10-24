# $NetBSD: Makefile,v 1.2 2023/10/24 22:11:21 wiz Exp $

DISTNAME=	calendarsupport-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	time

HOMEPAGE=	https://kontact.kde.org
COMMENT=	Calendar support library
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../misc/akonadi-notes/buildlink3.mk"
.include "../../misc/pimcommon/buildlink3.mk"
.include "../../time/akonadi-calendar/buildlink3.mk"
.include "../../time/kholidays/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
