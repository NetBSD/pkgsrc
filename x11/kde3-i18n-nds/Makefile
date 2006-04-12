# $NetBSD: Makefile,v 1.12 2006/04/12 11:37:20 markd Exp $

DISTNAME=	kde-i18n-nds-${_KDE_VERSION}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_KDE_I18N}

COMMENT=	Language bindings for the KDE desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

BUILD_USES_MSGFMT=	yes

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
