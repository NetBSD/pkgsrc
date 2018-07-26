# $NetBSD: Makefile,v 1.1 2018/07/26 16:02:31 jaapb Exp $

DISTNAME=	pybtex-docutils-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pybtex-docutils/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mcmtroffaes/pybtex-docutils
COMMENT=	Docutils backend for pybtex
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-pybtex-[0-9]*:../../textproc/py-pybtex
DEPENDS+=	${PYPKGPREFIX}-six>=1.5.2:../../lang/py-six


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
