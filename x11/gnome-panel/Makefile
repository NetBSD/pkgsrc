# $NetBSD: Makefile,v 1.1.1.1 2002/11/04 08:28:00 rh Exp $
#

DISTNAME=		gnome-panel-2.0.10
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-panel/2.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@hispabsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME2 panel application

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GNU_GETTEXT=	YES
USE_GMAKE=		YES
USE_PERL5=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--localstatedir=${SCROLLKEEPER_DATADIR}

post-extract:
	${CP} ${WRKSRC}/doc/reference/panel-applet/html/libpanel-applet.html \
	      ${WRKSRC}/doc/reference/panel-applet/html/index.html

.include "../../devel/GConf2/buildlink2.mk"
.include "../../devel/libwnck/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../textproc/scrollkeeper/buildlink2.mk"
.include "../../textproc/intltool/buildlink2.mk"
.include "../../textproc/gtk-doc/buildlink2.mk"
.include "../../x11/gnome-desktop/buildlink2.mk"
.include "../../x11/gnome2-control-center/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
