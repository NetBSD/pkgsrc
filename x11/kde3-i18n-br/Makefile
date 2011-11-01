# $NetBSD: Makefile,v 1.26 2011/11/01 06:02:55 sbd Exp $

DISTNAME=	kde-i18n-br-${_KDE_VERSION}
PKGREVISION=	8
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_KDE_I18N}

COMMENT=	Language bindings for the KDE desktop

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_TOOLS+=	msgfmt
BUILDLINK_DEPMETHOD.qt3-libs=	build
BUILDLINK_DEPMETHOD.kdelibs=	build

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
