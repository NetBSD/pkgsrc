# $NetBSD: Makefile,v 1.5 2015/04/05 23:26:27 rodent Exp $

DISTNAME=	Flask-Testing-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python www
MASTER_SITES=	https://pypi.python.org/packages/source/F/Flask-Testing/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/jarus/flask-testing
COMMENT=	Unit testing for Flask
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

.include "options.mk"

post-install:
	${CHMOD} go-w ${DESTDIR}${PREFIX}/${PYSITELIB}/${EGG_INFODIR}/*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
