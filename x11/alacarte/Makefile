# $NetBSD: Makefile,v 1.82 2019/08/11 13:25:10 wiz Exp $

DISTNAME=	alacarte-0.13.1
PKGREVISION=	45
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/alacarte/0.13/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.realistanew.com/projects/alacarte/
COMMENT=	Menu editor for the GNOME desktop
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	intltool perl pkg-config gmake msgfmt

PY_PATCHPLIST=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	36 37 # py-ORBit via py-gnome2, py-gtk2

SUBST_CLASSES+=	paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	Alacarte/util.py
SUBST_VARS.paths=	PREFIX
SUBST_VARS.paths+=	PKG_SYSCONFBASE

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.pygobject+=	${PYPKGPREFIX}-gobject>=2.15.1
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
# next two patterns should be kept the same!
BUILDLINK_API_DEPENDS.gnome-menus+=	gnome-menus>=2.27.92
.include "../../sysutils/gnome-menus/buildlink3.mk"
BUILDLINK_API_DEPENDS.py-gnome-menus+=	${PYPKGPREFIX}-gnome-menus>=2.27.92
.include "../../sysutils/py-gnome-menus/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
BUILDLINK_API_DEPENDS.pygtk2+=		${PYPKGPREFIX}-gtk2>=2.13.0
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
