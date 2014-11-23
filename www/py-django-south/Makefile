# $NetBSD: Makefile,v 1.8 2014/11/23 13:31:07 adam Exp $

DISTNAME=	South-1.0.1
PKGNAME=	${PYPKGPREFIX}-django-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/S/South/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://south.aeracode.org/
COMMENT=	Intelligent schema and data migrations for Django projects
LICENSE=	apache-2.0

WRKSRC=			${WRKDIR}/South-${PKGVERSION_NOREV}
#EGG_NAME=		${DISTNAME}
USE_LANGUAGES=		# empty

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
