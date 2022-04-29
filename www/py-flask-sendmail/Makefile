# $NetBSD: Makefile,v 1.5 2022/04/29 11:56:46 wiz Exp $

DISTNAME=	Flask-Sendmail-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	3
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Sendmail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ajford/flask-sendmail
COMMENT=	Flask extension to send mails with sendmail
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask

USE_LANGUAGES=	# empty

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
