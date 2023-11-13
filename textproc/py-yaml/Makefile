# $NetBSD: Makefile,v 1.30 2023/11/13 16:34:01 wiz Exp $

DISTNAME=	PyYAML-6.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyYAML/yaml/}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyYAML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yaml/pyyaml
COMMENT=	Collection of libraries to process YAML with Python
LICENSE=	mit

# does not build with cython-3.x as of 6.0.1
# https://github.com/yaml/pyyaml/issues/601
#DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
