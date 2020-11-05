# $NetBSD: Makefile,v 1.36 2020/11/05 09:07:13 ryoon Exp $

DISTNAME=	rest-0.7.93
PKGNAME=	${DISTNAME:S/rest/librest07/}
PKGREVISION=	16
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

PKGCONFIG_OVERRIDE+=	rest.pc.in rest-extras.pc.in

TEST_TARGET=	check

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
