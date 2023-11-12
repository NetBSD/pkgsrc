# $NetBSD: Makefile,v 1.107 2023/11/12 13:23:50 wiz Exp $

DISTNAME=	sawfish_1.13.0
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	5
CATEGORIES=	wm x11
MASTER_SITES=	https://download.tuxfamily.org/sawfish/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sawfish.tuxfamily.org/
COMMENT=	Extensible window manager that is fully configurable in Lisp
LICENSE=	gnu-gpl-v2 AND artistic-2.0 # the latter for sound files

GNU_CONFIGURE=		yes
INFO_FILES=		YES
PKGCONFIG_OVERRIDE+=	sawfish.pc.in
USE_TOOLS+=		gmake makeinfo msgfmt pkg-config xgettext
USE_TOOLS+=		gtar:run	# for librep run-time theme extraction
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--localedir=${PREFIX}/${PKGLOCALEDIR}/locale
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ENV+=		REP_ENV_PKGSRC=${REP_ENV_PKGSRC:Q}
MAKE_ENV+=		REP_ENV_PKGSRC=${REP_ENV_PKGSRC:Q}

SUBST_CLASSES+=		env
SUBST_STAGE.env=	pre-configure
SUBST_FILES.env=	lisp/sawfish/cfg/main.jl.in
SUBST_FILES.env+=	po/sawfish-xgettext
SUBST_FILES.env+=	scripts/sawfish-*.jl*
SUBST_SED.env=		-e 's,exec rep,exec env ${REP_ENV_PKGSRC} rep,g'

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
REP_ENV_PKGSRC=		LD_PRELOAD=/usr/lib/libpthread.so
.else
REP_ENV_PKGSRC=
.endif

.include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../lang/librep/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt+=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/rep-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
