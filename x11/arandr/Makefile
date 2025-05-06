# $NetBSD: Makefile,v 1.27 2025/05/06 12:10:56 wiz Exp $

DISTNAME=	arandr-0.1.11
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://christian.amsuess.com/tools/arandr/files/

MAINTAINER=	rga@sdf.lonestar.org
HOMEPAGE=	https://christian.amsuess.com/tools/arandr/
COMMENT=	Designed to provide a simple visual front end for XRandR
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-docutils>=0.6:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} != "native"
DEPENDS+=	xrandr>=1.2:../../x11/xrandr
.endif

PYTHON_VERSIONS_INCOMPATIBLE=	27

# Adjust setup.py
SUBST_CLASSES+=		setup
SUBST_STAGE.setup=	pre-build
SUBST_MESSAGE.setup=	Fixing setup.py
SUBST_FILES.setup=	setup.py
SUBST_SED.setup+=	-e 's,share/man/,${PKGMANDIR}/,g'

.include "../../lang/python/wheel.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
