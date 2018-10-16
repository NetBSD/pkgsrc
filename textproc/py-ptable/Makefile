# $NetBSD: Makefile,v 1.1 2018/10/16 13:47:01 adam Exp $

DISTNAME=	PTable-0.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PTable/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kxxoling/PTable
COMMENT=	Simple Python library for easily displaying tabular data
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} ptable ptable-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
