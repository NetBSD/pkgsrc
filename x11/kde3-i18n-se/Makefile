# $NetBSD: Makefile,v 1.24 2007/10/20 10:53:24 markd Exp $

DISTNAME=	kde-i18n-se-${_KDE_VERSION}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_KDE_I18N}

COMMENT=	Language bindings for the KDE desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_TOOLS+=	msgfmt
BUILDLINK_DEPMETHOD.qt3-libs=	build
BUILDLINK_DEPMETHOD.kdelibs=	build

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
