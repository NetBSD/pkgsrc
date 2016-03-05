# $NetBSD: Makefile,v 1.40 2016/03/05 11:29:37 jperkin Exp $

# This section contains variables that might be overridden.
PKGNAME?=	${PKGNAME_BASE}
COMMENT?=	Converts HTML to indexed HTML, PDF and/or PostScript

# Normal package Makefile contents follow.
DISTNAME=	htmldoc-1.8.27-source
PKGNAME_BASE=	${DISTNAME:S/-source//}
PKGREVISION=	13
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.easysw.com/pub/htmldoc/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

CONFLICTS+=	htmldoc-[0-9]*
CONFLICTS+=	htmldoc-x11-[0-9]*

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.htmldoc.org/
LICENSE=	gnu-gpl-v2

# ps-pdf.cpp:3229: Internal compiler error. on 1.4 - 1.7 unknown
NOT_FOR_PLATFORM=	NetBSD-1.[3-4]*-alpha

.include "options.mk"

WRKSRC=			${WRKDIR}/${DISTNAME:S/-source//}
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

INSTALL_MAKE_FLAGS+=	bindir=${DESTDIR}${PREFIX}/bin
INSTALL_MAKE_FLAGS+=	datadir=${DESTDIR}${PREFIX}/share
INSTALL_MAKE_FLAGS+=	mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
