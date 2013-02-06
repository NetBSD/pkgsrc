# $NetBSD: Makefile,v 1.9 2013/02/06 23:24:16 jperkin Exp $

DISTNAME=	konsole-${_KDE_VERSION}
PKGREVISION=	6
CATEGORIES=	x11
COMMENT=	a terminal emulator for the K Desktop Environment

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kde-baseapps4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
