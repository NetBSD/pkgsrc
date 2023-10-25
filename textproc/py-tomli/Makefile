# $NetBSD: Makefile,v 1.11 2023/10/25 22:04:23 wiz Exp $

DISTNAME=	tomli-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tomli/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hukkin/tomli
COMMENT=	Lil' TOML parser
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core
TOOL_DEPENDS+=	${PYPKGPREFIX}-installer-[0-9]*:../../misc/py-installer

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

PY_PATCHPLIST=	yes

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} -m flit_core.wheel

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${PYTHONBIN} -m installer --destdir ${DESTDIR} --prefix ${PREFIX} dist/*.whl

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
