# $NetBSD: Makefile,v 1.6 2025/05/13 10:47:58 wiz Exp $

DISTNAME=	commonmark-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	3
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/commonmark/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rtfd/CommonMark-py
COMMENT=	Python parser for the CommonMark Markdown spec
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} cmark cmark-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
