# $NetBSD: Makefile,v 1.67 2022/01/10 01:46:46 ryoon Exp $

DISTNAME=	kde-baseapps-15.12.0
PKGNAME=	${DISTNAME:S/-1/4-1/}
PKGREVISION=	33
CATEGORIES=	x11
COMMENT=	Base modules for the KDE 4 integrated X11 desktop
MASTER_SITES=	${MASTER_SITE_KDE:=applications/15.12.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

CONFLICTS=	konq-plugins-[0-9]*

REPLACE_INTERPRETER+=	xdg-open
REPLACE.xdg-open.old=	.*/bin/env xdg-open
REPLACE.xdg-open.new=	${PREFIX}/bin/xdg-open
REPLACE_FILES.xdg-open=	lib/konq/Templates/Program.desktop

CHECK_INTERPRETER_SKIP=	share/kde/templates/.source/Program.desktop

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../x11/libkactivities4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kde-runtime4/buildlink3.mk"
.include "../../www/tidy/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
