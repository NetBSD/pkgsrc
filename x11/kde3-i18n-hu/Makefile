# $NetBSD: Makefile,v 1.1.1.1 2003/03/12 11:03:24 markd Exp $

DISTNAME=	kde-i18n-hu-${_KDE_VERSION}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITES_KDE:=kde-i18n/}

COMMENT=	Language bindings for the KDE desktop

.include "../../x11/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES

WRKSRC=		${WRKDIR}/kde-i18n-hu

.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
