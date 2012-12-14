# $NetBSD: Makefile,v 1.76 2012/12/14 17:23:28 tsutsui Exp $

DISTNAME=	mlterm-3.1.6
#PKGREVISION=
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mlterm/}

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://mlterm.sourceforge.net/
COMMENT=	Multilingual terminal emulator
LICENSE=	modified-bsd

MAKE_JOBS_SAFE=		no

# CODESET is only supported on NetBSD in 1.5T and later - see <langinfo.h>
NOT_FOR_PLATFORM=	NetBSD-1.[0-4]*-* NetBSD-1.5[A-S]-*

USE_TOOLS+=		pkg-config msgfmt
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

PKG_SYSCONFSUBDIR=	mlterm
EGDIR=			${PREFIX}/share/examples/mlterm
.for f in aafont color font key main menu taafont termcap tfont vaafont vfont \
	xim
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

CONFIGURE_ARGS+=	--with-imagelib=gdk-pixbuf
CONFIGURE_ARGS+=	--without-libiconv-prefix
CONFIGURE_ARGS+=	--without-libintl-prefix
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples

.include "options.mk"

SUBST_CLASSES+=		link
SUBST_MESSAGE.link=	Fixing hardcoded paths and link options.
SUBST_STAGE.link=	post-patch
SUBST_FILES.link=	Makefile.in */Makefile.in */*/Makefile.in \
			*/*/*/Makefile.in man/mlterm.1
SUBST_SED.link=		-e 's|(LIBTOOL_LINK).*(LIBS)|& ${X11_LDFLAGS:M*:Q}|g'
SUBST_SED.link+=	-e 's|(LIBTOOL_LINK).*(LIBDIR)|& ${X11_LDFLAGS:M*:Q}|g'
SUBST_SED.link+=	-e 's|/usr/local/|${PREFIX}/|g'
SUBST_SED.link+=	-e 's|/usr/X11R7/|${X11BASE}/|g'

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
