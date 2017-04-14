# $NetBSD: Makefile,v 1.1 2017/04/14 12:22:25 leot Exp $

DISTNAME=	jsbeautifier-1.6.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsbeautifier/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jsbeautifier.org/
COMMENT=	JavaScript unobfuscator and beautifier
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-editorconfig-core>=0.12.0:../../devel/py-editorconfig-core
DEPENDS+=	${PYPKGPREFIX}-six>=1.6.1:../../lang/py-six

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/js-beautify ${DESTDIR}${PREFIX}/bin/js-beautify-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
