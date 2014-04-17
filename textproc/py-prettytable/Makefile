# $NetBSD: Makefile,v 1.4 2014/04/17 21:11:31 imil Exp $
#

DISTNAME=	prettytable-0.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://pypi.python.org/packages/source/P/PrettyTable/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/prettytable/
COMMENT=	Simple Python library for easily displaying tabular data
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

post-extract:
	${CHMOD} -R a+r ${WRKSRC}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
