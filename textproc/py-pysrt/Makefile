# $NetBSD: Makefile,v 1.5 2022/07/03 12:13:07 wiz Exp $

DISTNAME=	pysrt-1.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pysrt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/byroot/pysrt
COMMENT=	Python parser for SubRip (srt) files
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONED_DEPENDENCIES+=	chardet

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} srt srt-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
