# $NetBSD: Makefile,v 1.3 2003/05/02 11:57:24 wiz Exp $

DISTNAME=	kde-i18n-xh-${_KDE_VERSION}
PKGREVISION=	1
WRKSRC=		${WRKDIR}/kde-i18n-xh
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITES_KDE:=kde-i18n/}

COMMENT=	Language bindings for the KDE desktop

.include "../../x11/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES

.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
