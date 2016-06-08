# $NetBSD: Makefile,v 1.11 2016/06/08 17:43:41 wiz Exp $

DISTNAME=	xlrd-0.9.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xlrd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lexicon.net/sjmachin/xlrd.htm
COMMENT=	Python library to extract data from Microsoft Excel spreadsheet files
LICENSE=	modified-bsd

USE_LANGUAGES=		#none

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
