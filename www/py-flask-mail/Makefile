# $NetBSD: Makefile,v 1.5 2014/12/31 13:57:32 wiz Exp $

DISTNAME=	Flask-Mail-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Flask-Mail/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://pythonhosted.org/Flask-Mail/
COMMENT=	Flask extension for sending email
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

DEPENDS+=	${PYPKGPREFIX}-blinker-[0-9]*:../../devel/py-blinker
DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
