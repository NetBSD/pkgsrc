# $NetBSD: Makefile,v 1.21 2026/01/27 08:41:04 wiz Exp $

DISTNAME=	wxpython-4.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/wxp/wxP/}
PKGREVISION=	1
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wxPython/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wxpython.org/pages/downloads/
COMMENT=	GUI Toolkit for Python
# LGPLv2 with additional permission; http://opensource.org/licenses/wxwindows
LICENSE=	gnu-lgpl-v2

EGG_NAME=	${DISTNAME:S/wxp/wxP/}
WRKSRC=		${WRKDIR}/${DISTNAME:S/wxp/wxP/}

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=3.0.10:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-requests>=2.26.0:../../devel/py-requests
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-sip6>=6.12.0:../../x11/py-sip6
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
MAKE_ENV+=	WX_CONFIG=wx-config-3.2
PYDISTUTILSPKG=	no

PYTHON_SELF_CONFLICT=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../mk/bsd.prefs.mk"

BUILD_ARGS+=	--destdir=${DESTDIR}
BUILD_ARGS+=	--prefix=${PREFIX}
BUILD_ARGS+=	--release
BUILD_ARGS+=	--use_syswx
.if defined(MAKE_JOBS) && !empty(MAKE_JOBS) && !(defined(MAKE_JOBS_SAFE) && ${MAKE_JOBS_SAFE:U:tl} == no)
BUILD_ARGS+=	--jobs=${MAKE_JOBS}
.endif

post-patch:
	# upstream (incorrectly) installs patch .orig files
	${RM} -f ${WRKSRC}/wx/svg/_nanosvg.pyx.orig

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${TOOL_PYTHONBIN} build.py ${BUILD_ARGS} build_py

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${TOOL_PYTHONBIN} build.py ${BUILD_ARGS} install_py

.include "../../lang/python/egg.mk"
.include "../../x11/wxGTK32/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
