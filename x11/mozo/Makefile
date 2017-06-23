# $NetBSD: Makefile,v 1.4 2017/06/23 17:31:53 youri Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mozo-${VERSION}
CATEGORIES=	x11

COMMENT=	Menu editor for MATE

DEPENDS+=			${PYPKGPREFIX}-gtk2>=2.13.0:../../x11/py-gtk2
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-gtk2

PY_PATCHPLIST=	yes

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/mate-menus/buildlink3.mk"
.include "../../devel/py-gobject3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
