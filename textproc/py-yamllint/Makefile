# $NetBSD: Makefile,v 1.2 2022/08/02 09:45:58 adam Exp $

DISTNAME=	yamllint-1.27.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yamllint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/adrienverge/yamllint
COMMENT=	Linter for YAML files
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-pathspec>=0.5.3:../../devel/py-pathspec
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} yamllint yamllint-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
