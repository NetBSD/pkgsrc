# $NetBSD: Makefile,v 1.41 2026/10/16 19:44:24 adam Exp $

DISTNAME=	pyyaml-6.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyYAML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yaml/pyyaml
COMMENT=	Collection of libraries to process YAML with Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=3.0:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/wheel.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
