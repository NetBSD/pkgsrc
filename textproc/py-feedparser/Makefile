# $NetBSD: Makefile,v 1.2 2004/06/30 20:17:35 schmonz Exp $
#

DISTNAME=		feedparser-3.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=feedparser/}
EXTRACT_SUFX=		.zip

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://feedparser.org/
COMMENT=		Parse RSS and Atom feeds in Python

WRKSRC=			${WRKDIR}/feedparser
USE_BUILDLINK3=		yes

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED?=	23 23pth 22 22pth 21 21pth

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
