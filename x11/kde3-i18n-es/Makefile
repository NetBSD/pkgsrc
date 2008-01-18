# $NetBSD: Makefile,v 1.32 2008/01/18 05:09:59 tnn Exp $

DISTNAME=	kde-i18n-es-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_KDE_I18N}

COMMENT=	Language bindings for the KDE desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_TOOLS+=		msgfmt
BUILDLINK_DEPMETHOD.qt3-libs=	build
BUILDLINK_DEPMETHOD.kdelibs=	build

SUBST_CLASSES+=		common
SUBST_STAGE.common=	post-patch
SUBST_MESSAGE.common=	Fix common documentation path.
SUBST_FILES.common=	docs/common/Makefile.in
SUBST_SED.common=	-e s:/docs/common:/common:

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
