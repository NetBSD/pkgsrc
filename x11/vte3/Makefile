# $NetBSD: Makefile,v 1.22 2019/07/21 22:24:20 wiz Exp $

DISTNAME=	vte-0.54.3
PKGNAME=	${DISTNAME:S/vte/vte3/}
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/vte/0.54/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Terminal widget with improved accessibility and I18N support
LICENSE=	gnu-lgpl-v2

PKGCONFIG_OVERRIDE+=	vte.pc.in

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config bash
USE_LANGUAGES=		c c++14
# for c++14 \todo
GCC_REQD+=		5

BUILDLINK_TRANSFORM+=	rm:-Werror=format=2

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--disable-Bsymbolic
.else
CONFIGURE_ARGS+=	--enable-Bsymbolic=auto
.endif
CONFIGURE_ARGS+=	--disable-introspection
CONFIGURE_ARGS+=	--disable-vala

.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
