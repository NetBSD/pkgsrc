# $NetBSD: Makefile,v 1.2 2020/09/11 08:16:18 adam Exp $

DISTNAME=	commonmark-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/commonmark/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rtfd/CommonMark-py
COMMENT=	Python parser for the CommonMark Markdown spec
LICENSE=	modified-bsd

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-future>=0.14.0:../../devel/py-future
.endif

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} cmark cmark-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
