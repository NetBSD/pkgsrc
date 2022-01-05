# $NetBSD: Makefile,v 1.14 2022/01/05 20:07:11 wiz Exp $

DISTNAME=	cssutils-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cssutils/}

MAINTAINER=	rhialto@falu.nl
HOMEPAGE=	http://cthedot.de/cssutils/
COMMENT=	Cascading Style Sheets parser and library for Python
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	src/cssutils/*.py src/cssutils/scripts/*.py

USE_PKG_RESOURCES=	yes

# all files are group/others writable.
post-extract:
	chmod -R go-w ${WRKSRC}

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/csscapture ${DESTDIR}${PREFIX}/bin/csscapture-${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/csscombine ${DESTDIR}${PREFIX}/bin/csscombine-${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/cssparse ${DESTDIR}${PREFIX}/bin/cssparse-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
