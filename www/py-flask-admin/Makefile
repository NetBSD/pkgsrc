# $NetBSD: Makefile,v 1.20 2018/10/03 11:48:14 adam Exp $

DISTNAME=	Flask-Admin-1.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Admin/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/flask-admin/flask-admin
COMMENT=	Simple and extensible administrative interface framework for Flask
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
USE_TOOLS+=	pax

DEPENDS+=	${PYPKGPREFIX}-flask>=0.7:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-wtforms-[0-9]*:../../www/py-wtforms

EGDIR=			share/examples/${PKGBASE}
INSTALLATION_DIRS+=	${EGDIR}

post-extract:
	${RM} ${WRKSRC}/examples/__init__.py

post-install:
	${TOUCH} ${DESTDIR}${PREFIX}/${EGDIR}/__init__.py
	cd ${WRKSRC}/examples && pax -rwppm . ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
