# $NetBSD: Makefile,v 1.1.1.1 2009/10/02 20:00:13 markd Exp $

DISTNAME=	kdewebdev-${_KDE_VERSION}
CATEGORIES=	www
COMMENT=	HTML editor and tools suitable for experienced web developers

.include "../../meta-pkgs/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../www/tidy/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kdebase-runtime4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
