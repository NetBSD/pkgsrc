# $NetBSD: Makefile,v 1.7 2023/10/23 06:37:55 wiz Exp $

DISTNAME=	jrnl-1.9.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	time python
GITHUB_PROJECT=	jrnl
MASTER_SITES=	${MASTER_SITE_GITHUB:=maebert/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://jrnl.sh/
COMMENT=	Command line journal application
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cryptodome-[0-9]*:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.2:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-keyring>=3.3:../../security/py-keyring
DEPENDS+=	${PYPKGPREFIX}-keyrings.alt>=1.3:../../security/py-keyrings.alt
DEPENDS+=	${PYPKGPREFIX}-parsedatetime>=1.2:../../time/py-parsedatetime
DEPENDS+=	${PYPKGPREFIX}-pytz>=2013b:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-six>=1.6.1:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-tzlocal>=1.1:../../time/py-tzlocal

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-keyring

USE_PKG_RESOURCES=	yes

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/jrnl ${DESTDIR}${PREFIX}/bin/jrnl-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
