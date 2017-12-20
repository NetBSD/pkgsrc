# $NetBSD: Makefile,v 1.2 2017/12/20 11:08:06 leot Exp $

DISTNAME=	jrnl-1.9.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
GITHUB_PROJECT=	jrnl
MASTER_SITES=	${MASTER_SITE_GITHUB:=maebert/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://jrnl.sh/
COMMENT=	Command line journal application
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-crypto>=2.6:../../security/py-crypto
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.2:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-keyring>=3.3:../../security/py-keyring
DEPENDS+=	${PYPKGPREFIX}-keyrings.alt>=1.3:../../security/py-keyrings.alt
DEPENDS+=	${PYPKGPREFIX}-parsedatetime>=1.2:../../time/py-parsedatetime
DEPENDS+=	${PYPKGPREFIX}-pytz>=2013b:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline
DEPENDS+=	${PYPKGPREFIX}-six>=1.6.1:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-tzlocal>=1.1:../../time/py-tzlocal

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/jrnl ${DESTDIR}${PREFIX}/bin/jrnl-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
