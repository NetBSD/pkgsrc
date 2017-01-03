# $NetBSD: Makefile,v 1.50 2017/01/03 13:23:04 jperkin Exp $

DISTNAME=		html2text-2016.9.19
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		converters python textproc 
MASTER_SITES=		${MASTER_SITE_PYPI:=h/html2text/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/Alir3z4/html2text
COMMENT=		Convert HTML into easy-to-read plain ASCII text
LICENSE=		gnu-gpl-v3

USE_LANGUAGES=		# none

REPLACE_PYTHON=	html2text/__init__.py

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/html2text ${DESTDIR}${PREFIX}/bin/html2text-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
