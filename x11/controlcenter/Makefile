# $NetBSD: Makefile,v 1.31 2001/09/27 23:18:59 jlam Exp $

DISTNAME=		control-center-1.4.0.1
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/control-center/}

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME control-center development library

DEPENDS+=		gnome-libs>=1.2.13:../../x11/gnome-libs
DEPENDS+=		gdk-pixbuf>=0.10.1:../../graphics/gdk-pixbuf
DEPENDS+=		gnome-vfs>=1.0:../../sysutils/gnome-vfs
DEPENDS+=		scrollkeeper-[0-9]*:../../textproc/scrollkeeper

USE_X11BASE=		YES
USE_GMAKE=		YES
USE_LIBINTL=		YES
BUILD_USES_MSGFMT=	YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

LOCALSTATEDIR=		/var/gnome

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR}
CONFIGURE_ARGS+=	--with-glib-prefix=${LOCALBASE}
CPPFLAGS+=		-I${LOCALBASE}/include 		# libintl.h

post-patch:
	@${ECHO} >>${WRKSRC}/control-center/cappletConf.sh.in ""

.include "../../mk/bsd.pkg.mk"
