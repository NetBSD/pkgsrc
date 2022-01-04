# $NetBSD: Makefile,v 1.5 2022/01/04 20:55:12 wiz Exp $

DISTNAME=	jrnl-1.9.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
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
DEPENDS+=	${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline
DEPENDS+=	${PYPKGPREFIX}-six>=1.6.1:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-tzlocal>=1.1:../../time/py-tzlocal

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-keyring

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/jrnl ${DESTDIR}${PREFIX}/bin/jrnl-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
