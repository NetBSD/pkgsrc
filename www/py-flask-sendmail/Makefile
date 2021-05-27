# $NetBSD: Makefile,v 1.1 2021/05/27 22:25:05 khorben Exp $

DISTNAME=	Flask-Sendmail-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Sendmail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ajford/flask-sendmail
COMMENT=	Flask extension to send mails with sendmail
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
