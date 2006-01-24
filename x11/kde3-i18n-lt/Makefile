# $NetBSD: Makefile,v 1.21 2006/01/24 07:32:56 wiz Exp $

DISTNAME=	kde-i18n-lt-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITES_KDE:=kde-i18n/}

COMMENT=	Language bindings for the KDE desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

BUILD_USES_MSGFMT=	yes

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
