# $NetBSD: Makefile,v 1.27 2020/06/20 16:00:07 nia Exp $

DISTNAME=	vte-0.60.3
PKGNAME=	${DISTNAME:S/vte/vte3/}
PKGREVISION=	1
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
USE_TOOLS+=		gmake intltool msgfmt pkg-config bash
USE_LANGUAGES=		c c++14
# for c++14 \todo
GCC_REQD+=		5

.include "../../devel/meson/build.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
