# $NetBSD: Makefile,v 1.1.1.1 2001/10/30 13:38:54 damon Exp $

DISTNAME=	multi-gnome-terminal-1.3.3
CATEGORIES=	gnome x11
MASTER_SITES=	http://multignometerm.sourceforge.net/

MAINTAINER=	damon@netbsd.org
HOMEPAGE=	http://multignometerm.sourceforge.net/
COMMENT=	Gnome tabbed terminal emulator

DEPENDS+=       libglade-*:../../devel/libglade

USE_GMAKE=		#defined
HAS_CONFIGURE=		#defined
CONFIGURE_ARGS+=	--prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
