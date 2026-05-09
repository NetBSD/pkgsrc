# $NetBSD: Makefile,v 1.36 2026/05/09 13:03:11 vins Exp $

DISTNAME=	librest-0.10.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/${PKGBASE}/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/librest
COMMENT=	Library for "RESTful" web services
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	librest07-[0-9]*
SUPERSEDES+=	librest07-[0-9]*
PREV_PKGPATH=	www/librest07

USE_TOOLS+=	msgfmt msgmerge pkg-config xgettext

.include "../../security/openssl/buildlink3.mk"

# see pkgsrc/security/mozilla-rootcerts
MESON_ARGS=	-Dca_certificates=true \
		-Dca_certificates_path=${SSLDIR}/certs/ca-certificates.crt

.include "options.mk"

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/rest-1.0.pc \
				output/meson-private/rest-extras-1.0.pc

BUILDLINK_DEPMETHOD.gobject-introspection=	build

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/libadwaita/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtksourceview5/buildlink3.mk"

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
