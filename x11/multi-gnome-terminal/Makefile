# $NetBSD: Makefile,v 1.6 2002/04/02 13:14:42 agc Exp $

DISTNAME=	multi-gnome-terminal-1.3.4
PKGREVISION=	1
CATEGORIES=	gnome x11
MASTER_SITES=	http://multignometerm.sourceforge.net/

MAINTAINER=	damon@netbsd.org
HOMEPAGE=	http://multignometerm.sourceforge.net/
COMMENT=	Gnome tabbed terminal emulator

DEPENDS+=	scrollkeeper-[0-9]*:../../textproc/scrollkeeper

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_X11BASE=	yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/libglade/buildlink.mk"
.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
