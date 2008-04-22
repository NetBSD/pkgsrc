# $NetBSD: Makefile,v 1.24 2008/04/22 16:24:31 jlam Exp $

# This section contains variables that might be overridden.
PKGNAME?=	${PKGNAME_BASE}
COMMENT?=	Converts HTML to indexed HTML, PDF and/or PostScript

# Normal package Makefile contents follow.
DISTNAME=	htmldoc-1.8.23-source
PKGNAME_BASE=	${DISTNAME:S/-source//}
PKGREVISION=	7
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.easysw.com/pub/htmldoc/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

CONFLICTS+=	htmldoc-[0-9]*
CONFLICTS+=	htmldoc-x11-[0-9]*

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.easysw.com/htmldoc/

# ps-pdf.cpp:3229: Internal compiler error. on 1.4 - 1.7 unknown
NOT_FOR_PLATFORM=	NetBSD-1.[3-4]*-alpha

PKG_DESTDIR_SUPPORT=	user-destdir

.include "options.mk"

WRKSRC=			${WRKDIR}/${DISTNAME:S/-source//}
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

INSTALL_MAKE_FLAGS+=	bindir=${DESTDIR}${PREFIX}/bin
INSTALL_MAKE_FLAGS+=	datadir=${DESTDIR}${PREFIX}/share
INSTALL_MAKE_FLAGS+=	mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
