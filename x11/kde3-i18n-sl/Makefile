# $NetBSD: Makefile,v 1.1.1.1 2003/03/12 11:12:02 markd Exp $

DISTNAME=	kde-i18n-sl-${_KDE_VERSION}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITES_KDE:=kde-i18n/}

COMMENT=	Language bindings for the KDE desktop

.include "../../x11/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES

WRKSRC=		${WRKDIR}/kde-i18n-sl

.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
