# $NetBSD: Makefile,v 1.4 2003/05/22 03:07:19 markd Exp $

DISTNAME=	kde-i18n-cs-${_KDE_VERSION}
WRKSRC=		${WRKDIR}/kde-i18n-cs
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITES_KDE:=kde-i18n/}

COMMENT=	Language bindings for the KDE desktop

.include "../../x11/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES

.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
