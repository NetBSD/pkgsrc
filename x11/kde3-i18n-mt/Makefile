# $NetBSD: Makefile,v 1.7 2003/08/05 13:43:00 drochner Exp $

DISTNAME=	kde-i18n-mt-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITES_KDE:=kde-i18n/}

COMMENT=	Language bindings for the KDE desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
