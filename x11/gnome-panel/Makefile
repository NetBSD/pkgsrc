# $NetBSD: Makefile,v 1.5 2003/02/15 12:02:33 jmmv Exp $
#

DISTNAME=		gnome-panel-2.2.0.1
PKGREVISION=		1
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-panel/2.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME2 panel application

DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_PERL5=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html
CONFIGURE_ARGS+=	--localstatedir=${SCROLLKEEPER_DATADIR}

EGDIR=			${PREFIX}/share/examples/gnome-panel
.if defined(PKG_SYSCONFDIR.libgnome)
CONF_FILES=		${EGDIR}/sound/events/mailcheck2.soundlist \
			${PKG_SYSCONFDIR.libgnome}/sound/events/mailcheck2.soundlist
.else
CONF_FILES=		${EGDIR}/sound/events/mailcheck2.soundlist \
			${PKG_SYSCONFBASE}/sound/events/mailcheck2.soundlist
.endif

GCONF2_SCHEMAS= 	clock.schemas
GCONF2_SCHEMAS+=	fish.schemas
GCONF2_SCHEMAS+=	gnome-panel-screenshot.schemas
GCONF2_SCHEMAS+=	mailcheck.schemas
GCONF2_SCHEMAS+=	pager.schemas
GCONF2_SCHEMAS+=	panel-global-config.schemas
GCONF2_SCHEMAS+=	panel-per-panel-config.schemas
GCONF2_SCHEMAS+=	tasklist.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libwnck/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../textproc/scrollkeeper/buildlink2.mk"
.include "../../x11/gnome-desktop/buildlink2.mk"
.include "../../x11/gnome2-control-center/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
