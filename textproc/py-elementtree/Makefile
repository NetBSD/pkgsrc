# $NetBSD: Makefile,v 1.10 2011/02/28 14:53:05 wiz Exp $
#

DISTNAME=		elementtree-1.2.6-20050316
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/-20050316//}
PKGREVISION=		3
CATEGORIES=		textproc
MASTER_SITES=		http://effbot.org/downloads/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://effbot.org/zone/element.htm
COMMENT=		Read XML and HTML files into trees of Element objects

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		${PYPKGPREFIX}-xml-[0-9]*:../../textproc/py-xml

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

USE_LANGUAGES=		# empty

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
