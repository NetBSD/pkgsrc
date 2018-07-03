# $NetBSD: Makefile,v 1.24 2018/07/03 07:58:11 adam Exp $

DISTNAME=	Jinja2-2.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=J/Jinja2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jinja.pocoo.org/
COMMENT=	Small but fast and easy to use stand-alone template engine
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-babel>=0.8:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-markupsafe>=0.23:../../textproc/py-markupsafe

USE_LANGUAGES=		# none

SUBST_CLASSES+=		unicode
SUBST_FILES.unicode=	jinja2/*.py
SUBST_STAGE.unicode=	pre-install
SUBST_SED.unicode+=	-e "s,u',',g"
SUBST_SED.unicode+=	-e 's,u",",g'

.include "../../lang/python/pyversion.mk"

# async byte-compilation fails for Python < 3.6
# see https://github.com/pallets/jinja/issues/643
PLIST_VARS+=	async
.if "${PYPKGPREFIX}" == "py36" || "${PYPKGPREFIX}" == "py37"
PLIST.async=	yes
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
