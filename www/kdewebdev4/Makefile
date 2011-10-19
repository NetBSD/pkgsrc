# $NetBSD: Makefile,v 1.16 2011/10/19 06:13:03 obache Exp $

DISTNAME=	kdewebdev-${_KDE_VERSION}
PKGREVISION=	2
CATEGORIES=	www
COMMENT=	HTML editor and tools suitable for experienced web developers

.include "../../meta-pkgs/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/tidy/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kdebase-runtime4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
