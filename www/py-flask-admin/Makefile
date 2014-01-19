# $NetBSD: Makefile,v 1.8 2014/01/19 20:42:28 kleink Exp $

DISTNAME=	Flask-Admin-1.0.7
DIST_SUBDIR=	py-flask-admin
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	3
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Flask-Admin/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/mrjoes/flask-admin/
COMMENT=	Simple and extensible administrative interface framework for Flask
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

EGG_NAME=	${DISTNAME:S/-/_/}

DEPENDS+=	${PYPKGPREFIX}-flask>=0.7:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-wtforms-[0-9]*:../../www/py-wtforms

post-install:
.for i in LICENSE select2.min.js
	${CHMOD} -x \
	    ${DESTDIR}${PREFIX}/${PYSITELIB}/flask_admin/static/select2/${i}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
