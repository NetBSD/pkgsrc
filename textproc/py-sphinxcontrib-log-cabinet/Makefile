# $NetBSD: Makefile,v 1.6 2024/10/14 06:46:03 wiz Exp $

DISTNAME=	sphinxcontrib-log-cabinet-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxcontrib-log-cabinet/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/davidism/sphinxcontrib-log-cabinet
COMMENT=	Organize changelog directives in Sphinx docs
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
