# $NetBSD: Makefile,v 1.89 2019/08/11 13:24:15 wiz Exp $

DISTNAME=	wmakerconf-2.11
PKGREVISION=	51
CATEGORIES=	x11 wm windowmaker
MASTER_SITES=	http://starplot.org/wmakerconf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://starplot.org/wmakerconf/
COMMENT=	Gtk+ based configuration tool for Window Maker
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gzip tar perl:run pkg-config msgfmt

.if defined(PKG_SYSCONFDIR.windowmaker)
CONFIGURE_ARGS+=	--with-wmakeretcprefix=${PKG_SYSCONFDIR.windowmaker}
.else
CONFIGURE_ARGS+=	--with-wmakeretcprefix=${PKG_SYSCONFDIR}/WindowMaker
.endif

CONFIGURE_ENV+=		gzip=${TOOLS_GZIP_CMD:Q}
CONFIGURE_ENV+=		perlpath=${PERL5:Q}
CONFIGURE_ENV+=		tar=${TOOLS_TAR:Q}

REPLACE_PERL+=		scripts/*.pl.in
USE_TOOLS+=		perl:run

LDFLAGS.SunOS+=		-lX11

post-extract:
	${MV} ${WRKSRC}/data/WMWmakerconf ${WRKSRC}/data/WMWmakerconf.in

pre-configure:
	${SED} -e 's|@PREFIX@|${PREFIX}|g' < ${WRKSRC}/data/WMWmakerconf.in \
		> ${WRKSRC}/data/WMWmakerconf

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wm/windowmaker/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
