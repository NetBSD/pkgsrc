# $NetBSD: Makefile,v 1.12 2006/01/24 07:33:01 wiz Exp $

DISTNAME=		wxhaskell-src-0.9.4
PKGNAME=		${DISTNAME:S/-src//}
PKGREVISION=		3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wxhaskell/}
EXTRACT_SUFX=		.zip

MAINTAINER=		augustss@NetBSD.org
HOMEPAGE=		http://wxhaskell.sourceforge.net/index.html
COMMENT=		wxGTK binding for Haskell

USE_TOOLS+=		gmake

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

MAKEFILE=		makefile
MAKE_FLAGS+=		X11BASE=${X11BASE:Q}

pre-configure:
	cd ${WRKSRC}; ./configure --prefix=${PREFIX} --with-opengl

.include "../../lang/ghc/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
