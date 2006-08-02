# $NetBSD: Makefile,v 1.17 2006/08/02 14:24:46 markd Exp $

DISTNAME=	kde-i18n-uz-${_KDE_VERSION}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_KDE_I18N}

COMMENT=	Language bindings for the KDE desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_TOOLS+=	msgfmt

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
