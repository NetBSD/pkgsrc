# $NetBSD: Makefile,v 1.4 2023/10/21 18:07:38 adam Exp $

DISTNAME=	types-PyYAML-6.0.12.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyYAML/yaml/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/types-PyYAML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python/typeshed
COMMENT=	Typing stubs for PyYAML
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
