# $NetBSD: Makefile,v 1.5 2002/03/13 17:37:59 fredb Exp $

DISTNAME=	multi-gnome-terminal-1.3.4
PKGREVISION=	1
CATEGORIES=	gnome x11
MASTER_SITES=	http://multignometerm.sourceforge.net/

MAINTAINER=	damon@netbsd.org
HOMEPAGE=	http://multignometerm.sourceforge.net/
COMMENT=	Gnome tabbed terminal emulator

DEPENDS+=	scrollkeeper-[0-9]*:../../textproc/scrollkeeper

USE_GMAKE=		#defined
HAS_CONFIGURE=		#defined
CONFIGURE_ARGS+=	--prefix=${PREFIX}
USE_X11BASE=		#defined

PLIST_SUBST+=	MKDIR='${MKDIR}' \
		RMDIR='${RMDIR}'

.include "../../devel/libglade/buildlink.mk"
.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
