# $NetBSD: Makefile,v 1.1.1.1 1999/09/07 00:34:03 jwise Exp $

DISTNAME=	xfce-3.1.0
CATEGORIES=	x11
MASTER_SITES=	http://www.xfce.org/archive/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.xfce.org/

DEPENDS+=       gettext-0.10.35:../../devel/gettext
DEPENDS+=	gtk+-1.2.4:../../x11/gtk
DEPENDS+=	xpm-3.4k:../../graphics/xpm

USE_X11=	yes
USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	XFCE_LOCALE_DIR=${PREFIX}/share/locale
CONFIGURE_ARGS+=--without-included-gettext --datadir=${PREFIX}/share
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
