# $NetBSD: Makefile,v 1.1.1.1 2012/03/20 05:07:48 markd Exp $

DISTNAME=	konsole-${_KDE_VERSION}
CATEGORIES=	x11
COMMENT=	a terminal emulator for the K Desktop Environment

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kde-baseapps4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
