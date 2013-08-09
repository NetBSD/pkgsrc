# $NetBSD: Makefile,v 1.4 2013/08/09 07:28:24 adam Exp $

DISTNAME=	south-0.8.1
PKGNAME=	${PYPKGPREFIX}-django-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://www.aeracode.org/releases/south/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://south.aeracode.org/
COMMENT=	Intelligent schema and data migrations for Django projects
LICENSE=	apache-2.0

WRKSRC=			${WRKDIR}/South-${PKGVERSION_NOREV}
EGG_NAME=		${DISTNAME:S/south/South/}
USE_LANGUAGES=		# empty

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
