# $NetBSD: Makefile,v 1.1.1.1 2006/12/15 19:57:42 drochner Exp $
#

DISTNAME=	alacarte-0.10.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/alacarte/0.10/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.realistanew.com/projects/alacarte/
COMMENT=	Menu editor for the GNOME desktop

GNU_CONFIGURE=	yes
USE_TOOLS+=	intltool perl pkg-config gmake

PYTHON_VERSIONS_ACCEPTED= 24
PY_PATCHPLIST=	yes

SUBST_CLASSES+=	paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	Alacarte/util.py Alacarte/DialogHandler.py
SUBST_SED.paths=	-e "s;@PREFIX@;${PREFIX};g" -e "s;@PKG_SYSCONFBASE@;${PKG_SYSCONFBASE};g"

.include "../../sysutils/gnome-menus/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../sysutils/py-gnome-menus/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
