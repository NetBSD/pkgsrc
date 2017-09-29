# $NetBSD: Makefile,v 1.1 2017/09/29 21:22:51 joerg Exp $

DISTNAME=	maya-0.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python time
MASTER_SITES=	${MASTER_SITE_PYPI:=m/maya/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kennethreitz/maya
COMMENT=	Human-friendly date and time handling
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=		${PYPKGPREFIX}-ruamel-yaml>=0.10.12:../../devel/py-ruamel-yaml
DEPENDS+=		${PYPKGPREFIX}-humanize-[0-9]*:../../textproc/py-humanize
DEPENDS+=		${PYPKGPREFIX}-dateparser-[0-9]*:../../time/py-dateparser
DEPENDS+=		${PYPKGPREFIX}-pendulum-[0-9]*:../../time/py-pendulum
DEPENDS+=		${PYPKGPREFIX}-tzlocal-[0-9]*:../../time/py-tzlocal

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
