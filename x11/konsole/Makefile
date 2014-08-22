# $NetBSD: Makefile,v 1.25 2014/08/22 11:24:47 wiz Exp $

DISTNAME=	konsole-${_KDE_VERSION}
PKGREVISION=	4
CATEGORIES=	x11
COMMENT=	Terminal emulator for the K Desktop Environment

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kde-baseapps4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
