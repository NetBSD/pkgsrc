# $NetBSD: Makefile,v 1.34 2020/11/17 12:05:01 nia Exp $

DISTNAME=	vte-0.60.3
PKGNAME=	${DISTNAME:S/vte/vte3/}
PKGREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/vte/0.60/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Terminal widget with improved accessibility and I18N support
LICENSE=	gnu-lgpl-v2

PKGCONFIG_OVERRIDE_STAGE=	post-configure
PKGCONFIG_OVERRIDE+=		output/meson-private/vte-2.91.pc

GNU_CONFIGURE=		yes
USE_TOOLS+=		msgfmt pkg-config bash
USE_LANGUAGES=		c c++17
# for c++17
GCC_REQD+=		7

# Otherwise, this will fail on Linux distributions that don't
# have libsystemd.
MESON_ARGS+=		-D_systemd=false

CONF_FILES+=		${PREFIX}/share/examples/profile.d/vte.sh \
			${PKG_SYSCONFDIR}/profile.d/vte.sh

CONF_FILES+=		${PREFIX}/share/examples/profile.d/vte.csh \
			${PKG_SYSCONFDIR}/profile.d/vte.csh

.include "options.mk"
.include "../../devel/meson/build.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
