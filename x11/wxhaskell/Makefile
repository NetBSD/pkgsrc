# $NetBSD: Makefile,v 1.6 2005/05/22 08:43:21 augustss Exp $

DISTNAME=		wxhaskell-src-0.9.4
PKGNAME=		${DISTNAME:S/-src//}
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wxhaskell/}
EXTRACT_SUFX=		.zip

MAINTAINER=		augustss@NetBSD.org
HOMEPAGE=		http://wxhaskell.sourceforge.net/index.html
COMMENT=		wxGTK binding for Haskell

USE_GNU_TOOLS+=		make
USE_X11=		yes

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

MAKEFILE=		makefile
MAKE_FLAGS=		X11BASE=${X11BASE}

pre-configure:
	cd ${WRKSRC}; ./configure --prefix=${PREFIX} --with-opengl


.include "../../lang/ghc/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
