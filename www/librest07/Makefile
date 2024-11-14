# $NetBSD: Makefile,v 1.48 2024/11/14 22:22:07 wiz Exp $

DISTNAME=	rest-0.7.93
PKGNAME=	${DISTNAME:S/rest/librest07/}
PKGREVISION=	27
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/rest/0.7/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/librest
COMMENT=	Library for "RESTful" web services
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
# see pkgsrc/security/mozilla-rootcerts
CONFIGURE_ARGS+=	--with-ca-certificates=/etc/ssl/certs/ca-certificates.crt
CONFIGURE_ARGS+=	--enable-introspection=yes

PKGCONFIG_OVERRIDE+=	rest.pc.in rest-extras.pc.in

TEST_TARGET=	check

.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
