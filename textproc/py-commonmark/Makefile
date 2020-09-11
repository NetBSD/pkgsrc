# $NetBSD: Makefile,v 1.1 2020/09/11 00:46:00 js Exp $

DISTNAME=	commonmark-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc www
MASTER_SITES=	${MASTER_SITE_PYPI:=c/commonmark/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/rtfd/CommonMark-py
COMMENT=	Python parser for the CommonMark Markdown spec
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-future>=0.15.2:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-hypothesis>=3.4.2:../../devel/py-hypothesis

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} cmark cmark-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
