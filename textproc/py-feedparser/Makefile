# $NetBSD: Makefile,v 1.6 2005/01/27 03:46:30 schmonz Exp $
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
PYTHON_VERSIONS_ACCEPTED?=	24 23 22 21

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
