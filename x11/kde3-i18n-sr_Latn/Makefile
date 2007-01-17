# $NetBSD: Makefile,v 1.17 2007/01/17 23:47:25 wiz Exp $

DISTNAME=	kde-i18n-sr@Latn-${_KDE_VERSION}
PKGNAME=	${DISTNAME:S/@/_/}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_KDE_I18N}

COMMENT=	Language bindings for the KDE desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_TOOLS+=	msgfmt

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
