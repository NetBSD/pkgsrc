# $NetBSD: Makefile,v 1.6 2023/10/23 06:37:57 wiz Exp $

DISTNAME=	tuir-1.29.0
PKGREVISION=	5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tuir/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/ajak/tuir
COMMENT=	Browse Reddit from your terminal
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-kitchen-[0-9]*:../../devel/py-kitchen
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_FILES.man+=	setup.py
SUBST_SED.man+=		-e "s,share/man/man1,${PKGMANDIR}/man1,g"

PYTHON_VERSIONS_INCOMPATIBLE=	27
USE_PKG_RESOURCES=		yes

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
