# $NetBSD: Makefile,v 1.1 2015/12/04 21:46:47 wiz Exp $

DISTNAME=	betamax-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=b/betamax/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/betamax
COMMENT=	VCR imitation for python-requests
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
