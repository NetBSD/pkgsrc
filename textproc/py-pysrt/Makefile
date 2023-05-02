# $NetBSD: Makefile,v 1.6 2023/05/02 17:20:19 wiz Exp $

DISTNAME=	pysrt-1.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pysrt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/byroot/pysrt
COMMENT=	Python parser for SubRip (srt) files
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} srt srt-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
