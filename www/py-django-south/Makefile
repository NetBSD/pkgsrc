# $NetBSD: Makefile,v 1.11 2020/01/26 17:32:23 rillig Exp $

DISTNAME=	South-1.0.1
PKGNAME=	${PYPKGPREFIX}-django-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/South/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://south.aeracode.org/
COMMENT=	Intelligent schema and data migrations for Django projects
LICENSE=	apache-2.0

WRKSRC=			${WRKDIR}/South-${PKGVERSION_NOREV}
USE_LANGUAGES=		# empty

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
