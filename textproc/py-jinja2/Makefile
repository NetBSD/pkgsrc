# $NetBSD: Makefile,v 1.21 2017/05/04 18:11:09 adam Exp $

DISTNAME=	Jinja2-2.9.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=J/Jinja2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jinja.pocoo.org/
COMMENT=	Small but fast and easy to use stand-alone template engine
LICENSE=	modified-bsd

USE_LANGUAGES=		# none

DEPENDS+=	${PYPKGPREFIX}-markupsafe-[0-9]*:../../textproc/py-markupsafe

SUBST_CLASSES+=		unicode
SUBST_FILES.unicode=	jinja2/*.py
SUBST_STAGE.unicode=	pre-install
SUBST_SED.unicode+=	-e "s,u',',g"
SUBST_SED.unicode+=	-e 's,u",",g'

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
