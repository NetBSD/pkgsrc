# $NetBSD: Makefile,v 1.33 2008/01/18 05:10:03 tnn Exp $

DISTNAME=	kde-i18n-ro-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_KDE_I18N}

COMMENT=	Language bindings for the KDE desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_TOOLS+=		msgfmt

SUBST_CLASSES+=		common
SUBST_STAGE.common=	post-patch
SUBST_MESSAGE.common=	Fix common documentation path.
SUBST_FILES.common=	docs/common/Makefile.in
SUBST_SED.common=	-e s:/docs/common:/common:

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
