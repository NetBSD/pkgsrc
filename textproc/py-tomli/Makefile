# $NetBSD: Makefile,v 1.4 2022/01/07 16:33:21 adam Exp $

DISTNAME=	tomli-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tomli/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hukkin/tomli
COMMENT=	Lil' TOML parser
LICENSE=	mit

# It is possible to install this using flit_core, see
# https://github.com/takluyver/flit/pull/441/files
# for details. For now we keep using setuptools.

PYTHON_VERSIONS_INCOMPATIBLE=	27

PYSETUP=	-c 'from setuptools import setup; setup(name="tomli", version="${PKGVERSION_NOREV}", packages=["tomli"], package_data={"": ["*"]})'

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
