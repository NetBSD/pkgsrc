# $NetBSD: Makefile,v 1.3 2022/12/06 14:41:40 vins Exp $

DISTNAME=	1e158fb20108
PKGNAME=	xss-lock-0.3.0
CATEGORIES=	x11
MASTER_SITES=	https://bitbucket.org/raymonad/xss-lock/get/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://bitbucket.org/raymonad/xss-lock
COMMENT=	Use external locker as X screen saver
LICENSE=	mit

USE_TOOLS+=	pkg-config

PYTHON_FOR_BUILD_ONLY=	tool
# Requires rst2man to generate man page
TOOL_DEPENDS+=		${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils

SUBST_CLASSES+=		doc
SUBST_MESSAGE.doc=	Fixing rst2man name due to python versioning.
SUBST_STAGE.doc=	pre-configure
SUBST_FILES.doc=	doc/CMakeLists.txt
SUBST_SED.doc=		-e 's,rst2man.py,rst2man-${PYVERSSUFFIX},g'

USE_CMAKE=	yes
CMAKE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release

WRKSRC=		${WRKDIR}/raymonad-xss-lock-${DISTNAME}

.include "../../lang/python/pyversion.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
