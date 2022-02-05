# $NetBSD: Makefile,v 1.1 2022/02/05 09:42:06 adam Exp $

DISTNAME=	pyyaml_env_tag-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyyaml_env_tag/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/waylan/pyyaml-env-tag
COMMENT=	Custom YAML tag for referencing environment variables
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-yaml>0:../../textproc/py-yaml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
