# $NetBSD: Makefile,v 1.1 2013/01/07 21:56:38 kleink Exp $

DISTNAME=	Flask-Admin-1.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Flask-Admin/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/mrjoes/flask-admin/
COMMENT=	Simple and extensible administrative interface framework for Flask
LICENSE=	modified-bsd

EGG_NAME=	${DISTNAME:S/-/_/}

DEPENDS+=	${PYPKGPREFIX}-flask-wtf>=0.6:../../www/py-flask-wtf

post-install:
.for i in select2.css spinner.gif
	${CHMOD} -x \
	    ${DESTDIR}${PREFIX}/${PYSITELIB}/flask_admin/static/select2/${i}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
