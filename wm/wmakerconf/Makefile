# $NetBSD: Makefile,v 1.3 2001/06/11 06:34:53 jlam Exp $
#

DISTNAME=	wmakerconf-2.7
CATEGORIES=	x11 wm
MASTER_SITES=	http://ulli.linuxave.net/wmakerconf/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://ulli.linuxave.net/wmakerconf/
COMMENT=	Gtk+ based configuration tool for Window Maker

DEPENDS+=	imlib-*:../../graphics/imlib
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	windowmaker-*:../../wm/windowmaker

USE_X11BASE=	yes
USE_PERL5=	yes
USE_LIBINTL=	yes

GNU_CONFIGURE=	yes

# for libProplist
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib

.include "../../mk/bsd.pkg.mk"
