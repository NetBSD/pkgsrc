# $NetBSD: Makefile,v 1.4 2018/04/18 19:54:20 kamil Exp $

GITHUB_PROJECT=	httpie
DISTNAME=	httpie-0.9.2
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=jakubroztocil/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/jakubroztocil/httpie
COMMENT=	Human-friendly command line HTTP client
LICENSE=	original-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-pygments>=1.6:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-requests>=2.2.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-curses>=${PY_DISTVERSION}:../../devel/py-curses

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
