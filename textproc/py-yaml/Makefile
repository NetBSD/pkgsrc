# $NetBSD: Makefile,v 1.29 2023/07/18 04:34:33 adam Exp $

DISTNAME=	PyYAML-6.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyYAML/yaml/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyYAML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yaml/pyyaml
COMMENT=	Collection of libraries to process YAML with Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
