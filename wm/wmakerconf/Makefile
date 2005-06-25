# $NetBSD: Makefile,v 1.28 2005/06/25 01:14:11 kristerw Exp $

DISTNAME=	wmakerconf-2.11
PKGREVISION=	1
CATEGORIES=	x11 wm windowmaker
MASTER_SITES=	http://starplot.org/wmakerconf/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://starplot.org/wmakerconf/
COMMENT=	Gtk+ based configuration tool for Window Maker

USE_PKGLOCALEDIR=	yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		tar

.if defined(PKG_SYSCONFDIR.windowmaker)
CONFIGURE_ARGS+=	--with-wmakeretcprefix=${PKG_SYSCONFDIR.windowmaker}
.else
CONFIGURE_ARGS+=	--with-wmakeretcprefix=${PKG_SYSCONFDIR}/WindowMaker
.endif

CONFIGURE_ENV+=		tar="${TOOLS_TAR}"

post-extract:
	${MV} ${WRKSRC}/data/WMWmakerconf ${WRKSRC}/data/WMWmakerconf.in

pre-configure:
	${SED} -e 's|@PREFIX@|${PREFIX}|g' < ${WRKSRC}/data/WMWmakerconf.in \
		> ${WRKSRC}/data/WMWmakerconf

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../wm/windowmaker/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
