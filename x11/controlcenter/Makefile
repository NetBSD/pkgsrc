# $NetBSD: Makefile,v 1.51 2003/11/12 01:31:52 salo Exp $

DISTNAME=		control-center-1.4.0.4
PKGREVISION=		4
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/control-center/1.4/}

MAINTAINER=		jlam@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME control-center development library

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
USE_GMAKE=		YES
USE_PKGLOCALEDIR=	YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

LOCALSTATEDIR=		${X11PREFIX}/var

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR}

post-patch:
	@${ECHO} >>${WRKSRC}/control-center/cappletConf.sh.in ""

post-install:
	${MKDIR} ${PREFIX}/share/control-center/capplets

.include "../../devel/popt/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../sysutils/gnome-vfs/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-libs/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
