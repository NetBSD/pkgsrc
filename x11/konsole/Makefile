# $NetBSD: Makefile,v 1.14 2013/05/21 12:49:37 markd Exp $

DISTNAME=	konsole-${_KDE_VERSION}
CATEGORIES=	x11
COMMENT=	Terminal emulator for the K Desktop Environment

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kde-baseapps4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
