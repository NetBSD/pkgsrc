# $NetBSD: Makefile,v 1.12 2018/11/12 03:53:11 ryoon Exp $

PKGREVISION= 1
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mozo-${VERSION}
CATEGORIES=	x11

COMMENT=	Menu editor for MATE

DEPENDS+=	${PYPKGPREFIX}-gtk2>=2.13.0:../../x11/py-gtk2
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2

PY_PATCHPLIST=	yes

.include "../../devel/py-gobject3-common/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/mate-menus/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
