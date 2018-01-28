# $NetBSD: Makefile,v 1.6 2018/01/28 16:36:59 wiz Exp $

DISTNAME=	Unidecode-1.0.22
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=U/Unidecode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/Unidecode/
COMMENT=	ASCII transliterations of Unicode text
LICENSE=	gnu-gpl-v2 # or newer

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} unidecode unidecode${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
