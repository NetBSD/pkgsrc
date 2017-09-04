# $NetBSD: Makefile,v 1.6 2017/09/04 18:55:10 wiz Exp $
#

DISTNAME=	prettytable-0.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PrettyTable/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/PrettyTable/
COMMENT=	Simple Python library for easily displaying tabular data
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

post-extract:
	${CHMOD} -R a+r ${WRKSRC}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
