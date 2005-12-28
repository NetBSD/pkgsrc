# $NetBSD: Makefile,v 1.9 2005/12/28 06:59:27 schmonz Exp $
#

DISTNAME=		feedparser-4.0.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=feedparser/}
EXTRACT_SUFX=		.zip

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://feedparser.org/
COMMENT=		Parse RSS and Atom feeds in Python

WRKSRC=			${WRKDIR}

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED?=	24 23 22 21

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
