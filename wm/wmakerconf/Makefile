# $NetBSD: Makefile,v 1.11.2.1 2002/06/30 06:24:30 jlam Exp $
#

DISTNAME=	wmakerconf-2.8.1
PKGREVISION=	1
CATEGORIES=	x11 wm
MASTER_SITES=	http://ulli.on.openave.net/wmakerconf/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://ulli.on.openave.net/wmakerconf/
COMMENT=	Gtk+ based configuration tool for Window Maker

USE_BUILDLINK2=		yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libproplist/buildlink2.mk"
.include "../../graphics/imlib/buildlink2.mk"
.include "../../wm/windowmaker/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
