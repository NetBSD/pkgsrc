# $NetBSD: Makefile,v 1.13 2008/06/12 02:14:52 joerg Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
