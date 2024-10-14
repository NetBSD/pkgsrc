# $NetBSD: Makefile,v 1.10 2024/10/14 06:46:04 wiz Exp $

DISTNAME=	jrnl-4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jrnl/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://jrnl.sh/
COMMENT=	Command line journal application
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4.0:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-cryptography>=3.0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.8:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-keyring>=21.0:../../security/py-keyring
DEPENDS+=	${PYPKGPREFIX}-parsedatetime>=2.6:../../time/py-parsedatetime
DEPENDS+=	${PYPKGPREFIX}-rich>=12.2.0:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.17.22:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-tzlocal>=4.0:../../time/py-tzlocal
DEPENDS+=	${PYPKGPREFIX}-xdg>=0.27.0:../../devel/py-xdg

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39	# Python 3.10 or newer

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/jrnl ${DESTDIR}${PREFIX}/bin/jrnl-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
