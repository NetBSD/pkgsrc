# $NetBSD: Makefile,v 1.2 2003/03/29 12:43:01 jmmv Exp $

DISTNAME=	kde-i18n-fr-${_KDE_VERSION}
WRKSRC=		${WRKDIR}/kde-i18n-fr
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITES_KDE:=kde-i18n/}

COMMENT=	Language bindings for the KDE desktop

.include "../../x11/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES

.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
