# $NetBSD: Makefile,v 1.20 2004/02/25 23:25:21 minskim Exp $
#

DISTNAME=	wmakerconf-2.8.1
PKGREVISION=	5
CATEGORIES=	x11 wm windowmaker
MASTER_SITES=	http://ulli.on.openave.net/wmakerconf/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://ulli.on.openave.net/wmakerconf/
COMMENT=	Gtk+ based configuration tool for Window Maker

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes

.if defined(PKG_SYSCONFDIR.windowmaker)
CONFIGURE_ARGS+=	--with-wmakeretcprefix=${PKG_SYSCONFDIR.windowmaker}
.else
CONFIGURE_ARGS+=	--with-wmakeretcprefix=${PKG_SYSCONFDIR}/WindowMaker
.endif

post-extract:
	${MV} ${WRKSRC}/data/WMWmakerconf ${WRKSRC}/data/WMWmakerconf.in

pre-configure:
	${SED} -e 's|@PREFIX@|${PREFIX}|g' < ${WRKSRC}/data/WMWmakerconf.in \
		> ${WRKSRC}/data/WMWmakerconf

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libproplist/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../wm/windowmaker/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
