# $NetBSD: Makefile,v 1.17 2009/05/20 06:40:30 wiz Exp $
#

DISTNAME=	alacarte-0.12.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/alacarte/0.12/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.realistanew.com/projects/alacarte/
COMMENT=	Menu editor for the GNOME desktop
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	intltool perl pkg-config gmake msgfmt
USE_DIRS+=	xdg-1.1

PYTHON_VERSIONS_ACCEPTED=	25 24
PY_PATCHPLIST=	yes

SUBST_CLASSES+=	paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	Alacarte/util.py
SUBST_SED.paths=	-e "s;@PREFIX@;${PREFIX};g" -e "s;@PKG_SYSCONFBASE@;${PKG_SYSCONFBASE};g"

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.pygobject+=	${PYPKGPREFIX}-gobject>=2.15.1
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.gnome-menus+=	gnome-menus>=2.22.2
.include "../../sysutils/gnome-menus/buildlink3.mk"
.include "../../sysutils/py-gnome-menus/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
BUILDLINK_API_DEPENDS.pygtk2+=		${PYPKGPREFIX}-gtk2>=2.13.0
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
