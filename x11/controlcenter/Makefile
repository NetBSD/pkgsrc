# $NetBSD: Makefile,v 1.37 2002/03/24 01:07:47 rh Exp $

DISTNAME=		control-center-1.4.0.4
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/control-center/}

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME control-center development library

DEPENDS+=			scrollkeeper-[0-9]*:../../textproc/scrollkeeper
BUILD_USES_MSGFMT=	YES

BUILDLINK_DEPENDS.gnome-libs=	gnome-libs>=1.4.1.2nb1

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

LOCALSTATEDIR=		${X11PREFIX}/var/gnome

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR}

post-patch:
	@${ECHO} >>${WRKSRC}/control-center/cappletConf.sh.in ""

.include "../../devel/popt/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../sysutils/gnome-vfs/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
