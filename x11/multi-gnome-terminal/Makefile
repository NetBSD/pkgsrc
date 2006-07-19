# $NetBSD: Makefile,v 1.31 2006/07/19 10:09:40 joerg Exp $

DISTNAME=	multi-gnome-terminal-1.6.1
PKGREVISION=	11
CATEGORIES=	gnome x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=multignometerm/}

MAINTAINER=	damon@NetBSD.org
HOMEPAGE=	http://multignometerm.sourceforge.net/
COMMENT=	Gnome tabbed terminal emulator

USE_DIRS+=		xdg-1.1
USE_X11BASE=		yes
USE_TOOLS+=		gmake intltool
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

CONFIGURE_ENV+=		ac_cv_prog_JADE=no
CONFIGURE_ARGS+=	--enable-gtk-doc=no

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"

.include "../../mk/bsd.pkg.mk"
