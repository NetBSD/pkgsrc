# $NetBSD: Makefile,v 1.1 2023/05/10 21:59:57 markd Exp $

DISTNAME=	robot-detection-0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/robot-detection/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rory/robot-detection/
COMMENT=	Detect web crawlers using HTTP User Agent
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
