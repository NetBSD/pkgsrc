# $NetBSD: Makefile,v 1.2 2015/02/08 21:08:21 imil Exp $

GHCOMMIT=	753a8d04e4499505140a67442ae3e21f608b377f
DISTNAME=	${GHCOMMIT}
EGG_NAME=	httpie-0.9.1
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	www
MASTER_SITES=	https://github.com/jakubroztocil/httpie/archive/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/jakubroztocil/httpie
COMMENT=	Human-friendly command line HTTP client
LICENSE=	original-bsd

WRKSRC=		${WRKDIR}/httpie-${GHCOMMIT}

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-pygments>=1.6:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-requests>=2.2.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-curses>=${PY_DISTVERSION}:../../devel/py-curses

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
