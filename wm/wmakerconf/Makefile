# $NetBSD: Makefile,v 1.2 2001/02/17 17:21:51 wiz Exp $
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
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

# for libProplist
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib

.include "../../mk/bsd.pkg.mk"
