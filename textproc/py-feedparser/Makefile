# $NetBSD: Makefile,v 1.4 2004/07/22 09:16:02 recht Exp $
#

DISTNAME=		feedparser-3.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc python
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
