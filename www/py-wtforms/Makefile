# $NetBSD: Makefile,v 1.5 2013/05/08 08:30:47 kleink Exp $

DISTNAME=	WTForms-1.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/W/WTForms/
EXTRACT_SUFX=	.zip

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://wtforms.simplecodes.com/
COMMENT=	Flexible forms validation and rendering library
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

PYTHON_VERSIONS_INCLUDE_3X=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	31

post-extract:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} -x {} \;

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
