# $NetBSD: Makefile,v 1.7 2002/07/16 13:14:59 agc Exp $

DISTNAME=	multi-gnome-terminal-1.3.4
PKGREVISION=	1
CATEGORIES=	gnome x11
MASTER_SITES=	http://multignometerm.sourceforge.net/

MAINTAINER=	damon@netbsd.org
HOMEPAGE=	http://multignometerm.sourceforge.net/
COMMENT=	Gnome tabbed terminal emulator

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_X11BASE=	yes

USE_BUILDLINK_ONLY=	yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/libglade/buildlink.mk"
.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../textproc/scrollkeeper/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
