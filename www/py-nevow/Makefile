# $NetBSD: Makefile,v 1.33 2022/01/05 20:07:11 wiz Exp $

DISTNAME=	Nevow-0.14.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=N/Nevow/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/twisted/nevow
COMMENT=	Next-generation web application templating system
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-twisted>=13.0:../../net/py-twisted

USE_LANGUAGES=		# none

PYTHON_VERSIONS_ACCEPTED=	27

USE_PKG_RESOURCES=	yes

INSTALLATION_DIRS+=	share/doc

post-install:
	cd ${DESTDIR}${PREFIX} && ${MV} doc share/doc/py-nevow

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
