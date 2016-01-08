# $NetBSD: Makefile,v 1.16 2016/01/08 17:05:47 kleink Exp $

DISTNAME=	Flask-Admin-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Admin/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/flask-admin/flask-admin
COMMENT=	Simple and extensible administrative interface framework for Flask
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty
USE_TOOLS+=	pax

DEPENDS+=	${PYPKGPREFIX}-flask>=0.7:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-wtforms-[0-9]*:../../www/py-wtforms

EGDIR=          	share/examples/${PKGBASE}
PLIST_SUBST+=   	EGDIR=${EGDIR}
INSTALLATION_DIRS+=     ${EGDIR}

post-extract:
	rm -f ${WRKSRC}/examples/__init__.py

post-install:
.for i in LICENSE select2.css select2.min.js
	${CHMOD} -x \
	    ${DESTDIR}${PREFIX}/${PYSITELIB}/flask_admin/static/vendor/select2/${i}
.endfor
	${TOUCH} ${DESTDIR}${PREFIX}/${EGDIR}/__init__.py
	cd ${WRKSRC}/examples && pax -rwppm . ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
