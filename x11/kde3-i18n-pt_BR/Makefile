# $NetBSD: Makefile,v 1.19 2005/06/18 21:02:21 markd Exp $

DISTNAME=	kde-i18n-pt_BR-${_KDE_VERSION}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITES_KDE:=kde-i18n/}

COMMENT=	Language bindings for the KDE desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

BUILD_USES_MSGFMT=	yes

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
