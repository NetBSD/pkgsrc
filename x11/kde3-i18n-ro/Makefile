# $NetBSD: Makefile,v 1.11 2004/01/12 10:20:21 cjep Exp $

DISTNAME=	kde-i18n-ro-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITES_KDE:=kde-i18n/}

COMMENT=	Language bindings for the KDE desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
