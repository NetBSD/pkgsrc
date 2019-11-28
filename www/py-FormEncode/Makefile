# $NetBSD: Makefile,v 1.4 2019/11/28 06:30:51 adam Exp $

DISTNAME=	FormEncode-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/FormEncode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://formencode.org/
COMMENT=	HTML form validation, generation, and conversion package
LICENSE=	python-software-foundation

TEST_DEPENDS+=	${PYPKGPREFIX}-country-[0-9]*:../../geography/py-country
TEST_DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
