# $NetBSD: Makefile,v 1.1.1.1 2009/10/02 19:43:39 markd Exp $

DISTNAME=	kdebase-${_KDE_VERSION}
CATEGORIES=	x11
COMMENT=	Base modules for the KDE 4 integrated X11 desktop

.include "../../meta-pkgs/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

# In 4.2.2, -j2 fails with:
# [ 44%] Building CXX object apps/konsole/src/CMakeFiles/konsolepart.dir/ColorSchemeEditor.o                                        
# .../kdebase-4.2.2/apps/konsole/src/ColorSchemeEditor.cpp:36:34: error: ui_ColorSchemeEditor.h: No such file or directory     
MAKE_JOBS_SAFE=	no

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kdebase-runtime4/buildlink3.mk"
.include "../../x11/kdebase-workspace4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
