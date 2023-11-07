# $NetBSD: Makefile,v 1.2 2023/11/07 22:38:09 wiz Exp $

DISTNAME=	postorius-1.3.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/postorius/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.list.org/
COMMENT=	The New Mailman Web UI
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-cmarkgfm>=0.8.0:../../textproc/py-cmarkgfm
DEPENDS+=	${PYPKGPREFIX}-django>=3.2:../../www/py-django3
DEPENDS+=	${PYPKGPREFIX}-django-mailman3>=1.3.8:../../www/py-django-mailman3
DEPENDS+=	${PYPKGPREFIX}-mailmanclient>=3.3.3:../../mail/py-mailmanclient
DEPENDS+=	${PYPKGPREFIX}-readme_renderer-[0-9]*:../../textproc/py-readme_renderer

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
