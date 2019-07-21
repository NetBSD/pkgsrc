# $NetBSD: Makefile,v 1.18 2019/07/21 22:26:02 wiz Exp $

PYTHON_VERSIONS_INCOMPATIBLE=	27
PKGREVISION= 1
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mozo-${VERSION:R}.1
CATEGORIES=	x11

COMMENT=	Menu editor for MATE

#DEPENDS+=	${PYPKGPREFIX}-gtk2>=2.13.0:../../x11/py-gtk2

PY_PATCHPLIST=	yes

.include "../../devel/py-gobject3-common/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/mate-menus/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
