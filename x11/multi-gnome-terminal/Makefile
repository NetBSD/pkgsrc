# $NetBSD: Makefile,v 1.3 2001/12/04 20:40:32 damon Exp $

DISTNAME=	multi-gnome-terminal-1.3.4
CATEGORIES=	gnome x11
MASTER_SITES=	http://multignometerm.sourceforge.net/

MAINTAINER=	damon@netbsd.org
HOMEPAGE=	http://multignometerm.sourceforge.net/
COMMENT=	Gnome tabbed terminal emulator

USE_GMAKE=		#defined
HAS_CONFIGURE=		#defined
CONFIGURE_ARGS+=	--prefix=${PREFIX}
USE_X11BASE=		#defined

PLIST_SUBST+=	MKDIR='${MKDIR}' \
		RMDIR='${RMDIR}'

.include "../../devel/libglade/buildlink.mk"
.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
