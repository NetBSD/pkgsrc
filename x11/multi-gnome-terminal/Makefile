# $NetBSD: Makefile,v 1.23 2004/10/03 00:18:36 tv Exp $

DISTNAME=	multi-gnome-terminal-1.6.1
PKGREVISION=	7
CATEGORIES=	gnome x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=multignometerm/}

MAINTAINER=	damon@NetBSD.org
HOMEPAGE=	http://multignometerm.sourceforge.net/
COMMENT=	Gnome tabbed terminal emulator

USE_BUILDLINK3=		yes
USE_DIRS+=		xdg-1.1
USE_X11BASE=		# defined
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined

CONFIGURE_ENV+=		ac_cv_prog_JADE=no
CONFIGURE_ARGS+=	--enable-gtk-doc=no

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"

.include "../../mk/bsd.pkg.mk"
