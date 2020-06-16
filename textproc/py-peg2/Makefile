# $NetBSD: Makefile,v 1.2 2020/06/16 09:53:52 adam Exp $

DISTNAME=	pyPEG2-2.15.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyPEG2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fdik.org/pyPEG2/
COMMENT=	Intrinsic PEG Parser-Interpreter for Python
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
