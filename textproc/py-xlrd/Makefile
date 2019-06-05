# $NetBSD: Makefile,v 1.14 2019/06/05 00:37:43 gutteridge Exp $

DISTNAME=	xlrd-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xlrd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-excel/xlrd
COMMENT=	Python library to extract data from Microsoft Excel spreadsheet files
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} runxlrd.py runxlrd-${PYVERSSUFFIX}.py || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
