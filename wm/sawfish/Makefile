# $NetBSD: Makefile,v 1.100 2022/04/04 00:44:53 gutteridge Exp $

DISTNAME=	sawfish-1.13.0
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=SawfishWM/}
GITHUB_TAG=	refs/tags/${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sawfish.tuxfamily.org/
COMMENT=	Extensible window manager that is fully configurable in Lisp
LICENSE=	gnu-gpl-v2 AND artistic-2.0 # for sound files

GNU_CONFIGURE=		yes
INFO_FILES=		YES
PKGCONFIG_OVERRIDE+=	sawfish.pc.in
USE_TOOLS+=		gmake makeinfo msgfmt pkg-config xgettext autoconf automake
USE_TOOLS+=		gtar:run	# for librep run-time theme extraction
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
WRKSRC=			${WRKDIR}/${PKGBASE}-${DISTNAME}

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

.if ${OPSYS} == "NetBSD" && empty(OS_VERSION:M1.*)
REP_ENV_PKGSRC=		LD_PRELOAD=/usr/lib/libpthread.so
.else
REP_ENV_PKGSRC=
.endif

# The upstream presently isn't providing a pre-generated configure.
pre-configure:
	cd ${WRKSRC} && autoreconf -iv

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
