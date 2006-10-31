# $NetBSD: Makefile,v 1.1.1.1 2006/10/31 22:39:18 joerg Exp $
#

DISTNAME=		markdown-1.6a
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=python-markdown/}
EXTRACT_SUFX=		.zip

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://www.freewisdom.org/projects/python-markdown/
COMMENT=		XHTML generator using a simple markup

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/markdown-1.6

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
