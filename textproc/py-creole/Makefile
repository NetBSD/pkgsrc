# $NetBSD: Makefile,v 1.13 2022/01/04 20:54:53 wiz Exp $

DISTNAME=	python-creole-1.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python-//}
PKGREVISION=	1
CATEGORIES=	textproc www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-creole/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://github.com/jedie/python-creole
COMMENT=	Markup converter in pure Python
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-textile-[0-9]*:../../textproc/py-textile
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=		# none

REPLACE_PYTHON+=	creole/*.py
REPLACE_PYTHON+=	creole/*/*.py

PYTHON_SELF_CONFLICT=	yes

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} setup.py nosetests

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
