# $NetBSD: Makefile,v 1.16 2004/04/20 14:38:39 markd Exp $

DISTNAME=	kde-i18n-ja-${_KDE_VERSION}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITES_KDE:=kde-i18n/}

COMMENT=	Language bindings for the KDE desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK3=		YES

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
