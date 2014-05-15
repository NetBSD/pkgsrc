# $NetBSD: Makefile,v 1.24 2014/05/15 14:41:59 adam Exp $

DISTNAME=	konsole-${_KDE_VERSION}
PKGREVISION=	3
CATEGORIES=	x11
COMMENT=	Terminal emulator for the K Desktop Environment

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kde-baseapps4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
