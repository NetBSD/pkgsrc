# $NetBSD: Makefile,v 1.18 2017/03/14 14:11:51 kleink Exp $

DISTNAME=	Flask-Admin-1.5.0
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
	${RM} -f ${WRKSRC}/examples/__init__.py
	${FIND} ${WRKSRC} -type f -name .DS_Store -print | ${XARGS} ${RM} -f

post-install:
	${FIND} \
	    ${DESTDIR}${PREFIX}/${PYSITELIB}/flask_admin/static \
	    ${DESTDIR}${PREFIX}/${PYSITELIB}/flask_admin/templates \
	    -type f -print | ${XARGS} ${CHMOD} -x
	${TOUCH} ${DESTDIR}${PREFIX}/${EGDIR}/__init__.py
	cd ${WRKSRC}/examples && pax -rwppm . ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
