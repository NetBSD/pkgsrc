# $NetBSD: Makefile,v 1.23 2004/11/09 10:30:31 wiz Exp $

DISTNAME=	wmakerconf-2.9.2
CATEGORIES=	x11 wm windowmaker
MASTER_SITES=	http://starplot.org/wmakerconf/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://starplot.org/wmakerconf/
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
.include "../../graphics/imlib/buildlink3.mk"
.include "../../wm/windowmaker/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
