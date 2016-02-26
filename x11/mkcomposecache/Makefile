# $NetBSD: Makefile,v 1.3 2016/02/26 11:27:16 jperkin Exp $
#

DISTNAME=	mkcomposecache-1.2.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Used for creating global (system-wide) Compose cache files
#LICENSE=	# XXX SUSE license ?

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ENV.SunOS+=	ADMIN_MAN_SUFFIX=8

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
