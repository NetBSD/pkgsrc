# $NetBSD: Makefile,v 1.26 2001/01/21 17:40:34 tron Exp $

DISTNAME=		control-center-1.2.2
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/control-center/}

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.gnome.org/

DEPENDS+=		gnome-libs>=1.2.0:../../x11/gnome-libs
DEPENDS+=		gdk-pixbuf>=0.7.0:../../graphics/gdk-pixbuf
BUILD_DEPENDS+=		msgfmt:../../devel/gettext

USE_X11BASE=		# defined
USE_GMAKE=		# defined
USE_LIBINTL=		# defined

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

LOCALSTATEDIR=		/var/gnome

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR} \
			--with-glib-prefix=${LOCALBASE}
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=		-I${LOCALBASE}/include 		# libintl.h

post-patch:
	@${ECHO} >>${WRKSRC}/control-center/cappletConf.sh.in ""

post-install:
	${RMDIR} ${PREFIX}/share/gnome/help/control-center/C/stylesheet-images

.include "../../mk/bsd.pkg.mk"
