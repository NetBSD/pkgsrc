# $NetBSD: Makefile,v 1.48 2014/02/12 23:18:52 tron Exp $

DISTNAME=	kde-i18n-sr@Latn-${_KDE_VERSION}
PKGNAME=	${DISTNAME:S/@/_/}
PKGREVISION=	24
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
