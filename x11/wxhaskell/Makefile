# $NetBSD: Makefile,v 1.1 2004/11/20 23:18:25 augustss Exp $

DISTNAME=		wxhaskell-0.8
CATEGORIES=		x11
MASTER_SITES=		http://voxel.dl.sourceforge.net/sourceforge/wxhaskell/
DISTFILES=		wxhaskell-src-0.8.zip

MAINTAINER=		augustss@NetBSD.org
HOMEPAGE=		http://wxhaskell.sourceforge.net/index.html
COMMENT=		wxGTK bindings for Haskell

BUILD_DEPENDS=          ghc>=6.2:../../lang/ghc
BUILD_DEPENDS+=		wxGTK>=2.4.2:../../x11/wxGTK

USE_GNU_TOOLS+=		make
USE_X11=		yes

MAKEFILE=		makefile
MAKE_FLAGS=		X11BASE=${X11BASE}

pre-configure:
	cd ${WRKSRC}; ./configure --prefix=${PREFIX} --with-opengl


.include "../../mk/bsd.pkg.mk"
