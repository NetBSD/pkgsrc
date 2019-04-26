# $NetBSD: Makefile,v 1.19 2019/04/26 13:14:17 maya Exp $

DISTNAME=		elementtree-1.2.6-20050316
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/-20050316//}
PKGREVISION=		4
CATEGORIES=		textproc
MASTER_SITES=		http://effbot.org/downloads/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://effbot.org/zone/element.htm
COMMENT=		Read XML and HTML files into trees of Element objects

DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

USE_LANGUAGES=		# empty

EGG_NAME=		elementtree-1.2.6_20050316

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
