# $NetBSD: Makefile,v 1.23 2022/01/10 09:05:01 wiz Exp $

DISTNAME=		elementtree-1.2.6-20050316
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/-20050316//}
PKGREVISION=		5
CATEGORIES=		textproc
MASTER_SITES=		http://effbot.org/downloads/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://effbot.org/zone/element.htm
COMMENT=		Read XML and HTML files into trees of Element objects

DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

USE_LANGUAGES=		# empty

EGG_NAME=		elementtree-1.2.6_20050316

PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
