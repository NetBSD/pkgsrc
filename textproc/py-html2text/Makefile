# $NetBSD: Makefile,v 1.55 2019/10/09 21:26:12 rhialto Exp $

DISTNAME=	html2text-2019.9.26
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/html2text/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://github.com/Alir3z4/html2text
COMMENT=	Convert HTML into easy-to-read plain ASCII text
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} html2text html2text-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
