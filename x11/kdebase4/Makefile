# $NetBSD: Makefile,v 1.21 2011/11/01 06:03:01 sbd Exp $

DISTNAME=	kdebase-${_KDE_VERSION}
PKGREVISION=	4
CATEGORIES=	x11
COMMENT=	Base modules for the KDE 4 integrated X11 desktop

.include "../../meta-pkgs/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

REPLACE_RUBY+=	apps/dolphin/src/khns/servicemenudeinstallation
REPLACE_RUBY+=	apps/dolphin/src/khns/servicemenuinstallation

.include "../../lang/ruby/replace.mk"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kdebase-runtime4/buildlink3.mk"
.include "../../x11/kdebase-workspace4/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
