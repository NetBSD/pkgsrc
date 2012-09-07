# $NetBSD: Makefile,v 1.65 2012/09/07 19:17:39 adam Exp $
#

DISTNAME=		sawfish-1.7.1
PKGREVISION=		6
CATEGORIES=		x11 wm
MASTER_SITES=		http://download.tuxfamily.org/sawfish/sawfish/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tnn@NetBSD.org
HOMEPAGE=		http://sawfish.wikia.com/
COMMENT=		Extensible window manager that is fully configurable in Lisp

CONFLICTS+=		sawfish-replibs-[0-9]*
CONFLICTS+=		sawfish-themes-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
INFO_FILES=		YES
PKGCONFIG_OVERRIDE+=	sawfish.pc.in
USE_TOOLS+=		gmake makeinfo msgfmt pkg-config xgettext
USE_TOOLS+=		gtar:run	# for librep run-time theme extraction
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}
MAKE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}
CONFIGURE_ENV+=		REP_ENV_PKGSRC=${REP_ENV_PKGSRC:Q}
MAKE_ENV+=		REP_ENV_PKGSRC=${REP_ENV_PKGSRC:Q}

SUBST_CLASSES+=		env
SUBST_STAGE.env=	pre-configure
SUBST_FILES.env=	lisp/sawfish/ui/main.jl.in po/sawfish-xgettext
SUBST_FILES.env+=	scripts/sawfish-*.jl*
SUBST_SED.env=		-e 's,exec rep,exec env ${REP_ENV_PKGSRC} rep,g'

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && empty(${OS_VERSION:M1.*})
REP_ENV_PKGSRC=		LD_PRELOAD=/usr/lib/libpthread.so
.else
REP_ENV_PKGSRC=
.endif

.include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.include "../../lang/librep/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt+=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/rep-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
