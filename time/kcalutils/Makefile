# $NetBSD: Makefile,v 1.57 2026/09/27 11:38:56 tnn Exp $

DISTNAME=	kcalutils-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	time

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	KDE calendar access library
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../misc/kidentitymanagement/buildlink3.mk"
.include "../../textproc/kf6-ktexttemplate/buildlink3.mk"
.include "../../time/kf6-kcalendarcore/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
