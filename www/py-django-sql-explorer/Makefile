# $NetBSD: Makefile,v 1.2 2018/10/03 10:47:20 adam Exp $

DISTNAME=	django-sql-explorer-1.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-sql-explorer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/epantry/django-sql-explorer
COMMENT=	Pluggable app that allows to execute SQL, view, and export the results
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-django>=1.7.0:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-sqlparse>=0.1.18:../../databases/py-sqlparse
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-unicodecsv>=0.14.1:../../databases/py-unicodecsv

USE_LANGUAGES=		# empty

# remove cache files from the distribution
post-extract:
	find ${WRKSRC} -type f \( -name '*.pyc' -or -name .DS_Store \) -print -delete

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
