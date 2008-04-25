# $NetBSD: Makefile,v 1.8 2008/04/25 20:39:12 joerg Exp $
#

DISTNAME=		elementtree-1.2.6-20050316
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/-20050316//}
PKGREVISION=		3
CATEGORIES=		textproc
MASTER_SITES=		http://effbot.org/downloads/

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://effbot.org/zone/element.htm
COMMENT=		Read XML and HTML files into trees of Element objects

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		${PYPKGPREFIX}-xml-[0-9]*:../../textproc/py-xml

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED=	25 24 23 21

USE_LANGUAGES=		# empty

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
