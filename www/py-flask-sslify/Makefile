# $NetBSD: Makefile,v 1.8 2022/04/29 11:56:46 wiz Exp $

DISTNAME=	Flask-SSLify-0.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python security
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-SSLify/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kennethreitz/flask-sslify
COMMENT=	Force SSL on your Flask app
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
