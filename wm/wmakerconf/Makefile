# $NetBSD: Makefile,v 1.4 2001/08/03 17:49:40 wiz Exp $
#

DISTNAME=	wmakerconf-2.8.1
CATEGORIES=	x11 wm
MASTER_SITES=	http://ulli.on.openave.net/wmakerconf/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://ulli.on.openave.net/wmakerconf/
COMMENT=	Gtk+ based configuration tool for Window Maker

USE_BUILDLINK_ONLY=	yes
USE_BUILDLINK_X11=	yes
USE_X11BASE=		yes
USE_PERL5=		yes
#USE_LIBINTL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../graphics/imlib/buildlink.mk"
.include "../../wm/windowmaker/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
