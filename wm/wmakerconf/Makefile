# $NetBSD: Makefile,v 1.9 2001/10/23 13:15:06 jlam Exp $
#

DISTNAME=	wmakerconf-2.8.1
CATEGORIES=	x11 wm
MASTER_SITES=	http://ulli.on.openave.net/wmakerconf/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://ulli.on.openave.net/wmakerconf/
COMMENT=	Gtk+ based configuration tool for Window Maker

USE_BUILDLINK_ONLY=	yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		wraster="${GET_WRASTER_FLAGS}"

.include "../../mk/x11.buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/libproplist/buildlink.mk"
.include "../../graphics/imlib/buildlink.mk"
.include "../../wm/windowmaker/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
