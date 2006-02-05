# $NetBSD: Makefile,v 1.11 2006/02/05 23:11:06 joerg Exp $
#

DISTNAME=		feedparser-4.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
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
