# $NetBSD: Makefile,v 1.45 2023/11/12 13:23:58 wiz Exp $

DISTNAME=	uhttpmock-0.5.3
PKGREVISION=	5
CATEGORIES=	www devel
MASTER_SITES=	http://tecnocode.co.uk/downloads/uhttpmock/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/groups/uhttpmock
COMMENT=	Library for mocking web service APIs which use HTTP or HTTPS
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	libuhttpmock/libuhttpmock.pc.in

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--no-as-needed

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
