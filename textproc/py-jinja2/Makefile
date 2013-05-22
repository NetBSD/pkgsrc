# $NetBSD: Makefile,v 1.9 2013/05/22 14:31:48 joerg Exp $

DISTNAME=	Jinja2-2.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/J/Jinja2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jinja.pocoo.org/2/
COMMENT=	Small but fast and easy to use stand-alone template engine
LICENSE=	modified-bsd

USE_LANGUAGES=		#none

PYTHON_VERSIONS_INCLUDE_3X=	yes

DEPENDS+=	${PYPKGPREFIX}-markupsafe-[0-9]*:../../textproc/py-markupsafe

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
