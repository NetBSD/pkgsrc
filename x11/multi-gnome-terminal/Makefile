# $NetBSD: Makefile,v 1.8 2002/09/23 22:42:44 jlam Exp $

DISTNAME=	multi-gnome-terminal-1.3.4
PKGREVISION=	1
CATEGORIES=	gnome x11
MASTER_SITES=	http://multignometerm.sourceforge.net/

MAINTAINER=	damon@netbsd.org
HOMEPAGE=	http://multignometerm.sourceforge.net/
COMMENT=	Gnome tabbed terminal emulator

USE_BUILDLINK2=		# defined
USE_X11BASE=		# defined
USE_GMAKE=		# defined
GNU_CONFIGURE=		# defined

USE_LIBTOOL=		# defined
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/libglade/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../textproc/scrollkeeper/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
