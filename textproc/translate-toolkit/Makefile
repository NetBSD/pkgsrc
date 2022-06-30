# $NetBSD: Makefile,v 1.7 2022/06/30 11:18:55 nia Exp $

DISTNAME=	translate-toolkit-3.0.0
PKGREVISION=	4
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/translate-toolkit/}

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	https://github.com/translate/translate
COMMENT=	Tools for working with translation files
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-lxml>=4.3.2:../../textproc/py-lxml

USE_LANGUAGES=	# none
USE_TOOLS+=	bash:run

REPLACE_BASH+=	tools/mozilla/build_firefox.sh
REPLACE_BASH+=	tools/junitmsgfmt
REPLACE_BASH+=	tools/posplit
REPLACE_BASH+=	tools/pomigrate2
REPLACE_BASH+=	tools/pocompendium
REPLACE_BASH+=	tools/pocommentclean
REPLACE_BASH+=	tools/poreencode
REPLACE_BASH+=	tools/popuretext

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
