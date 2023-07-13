# $NetBSD: Makefile,v 1.4 2023/07/13 10:03:30 wiz Exp $

DISTNAME=	filebrowser_safe-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/filebrowser_safe/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/stephenmcd/filebrowser-safe
COMMENT=	Permanent fork of FileBrowser asset manager for Mezzanine
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
