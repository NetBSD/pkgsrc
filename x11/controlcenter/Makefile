# $NetBSD: Makefile,v 1.60 2004/04/21 04:29:19 snj Exp $

DISTNAME=		control-center-1.4.0.4
PKGREVISION=		6
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/control-center/1.4/}

MAINTAINER=		jlam@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME control-center development library

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1
USE_X11BASE=		YES
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	YES

USE_LIBTOOL=		YES

LOCALSTATEDIR=		${X11PREFIX}/var

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR}

post-patch:
	@${ECHO} >>${WRKSRC}/control-center/cappletConf.sh.in ""

post-install:
	${MKDIR} ${PREFIX}/share/control-center/capplets

.include "../../devel/popt/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
