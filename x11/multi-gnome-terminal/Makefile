# $NetBSD: Makefile,v 1.21 2004/04/14 19:30:23 jmmv Exp $

DISTNAME=	multi-gnome-terminal-1.6.1
PKGREVISION=	6
CATEGORIES=	gnome x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=multignometerm/}

MAINTAINER=	damon@NetBSD.org
HOMEPAGE=	http://multignometerm.sourceforge.net/
COMMENT=	Gnome tabbed terminal emulator

USE_BUILDLINK2=		# defined
USE_DIRS+=		xdg-1.1
USE_X11BASE=		# defined
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined

CONFIGURE_ENV+=		ac_cv_prog_JADE=no
CONFIGURE_ARGS+=	--enable-gtk-doc=no

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"

.include "../../mk/bsd.pkg.mk"
