# $NetBSD: Makefile,v 1.9 2016/12/30 10:09:36 ryoon Exp $

H5LVER=		0.9999999
DISTNAME=	html5lib-python-${H5LVER}
PKGNAME=	${PYPKGPREFIX}-html5lib-${H5LVER}
CATEGORIES=	textproc www python
MASTER_SITES=	-https://github.com/html5lib/html5lib-python/archive/${H5LVER}${EXTRACT_SUFX}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://github.com/html5lib/html5lib-python
COMMENT=	HTML5 parser and tokenizer
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

EGG_NAME=	html5lib-${PKGVERSION_NOREV}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
