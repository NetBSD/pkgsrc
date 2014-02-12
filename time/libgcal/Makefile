# $NetBSD: Makefile,v 1.3 2014/02/12 23:18:42 tron Exp $
#

DISTNAME=	libgcal-0.9.6
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	http://libgcal.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libgcal/
COMMENT=	C library allows communication with google calendar and contacts
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libgcal.pc.in

.include "../../devel/check/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
