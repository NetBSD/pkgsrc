# $NetBSD: Makefile,v 1.19 2012/10/29 05:06:57 asau Exp $
#

.include "Makefile.common"

PKGREVISION=		4

CONFIGURE_ARGS+=	--disable-tk

PTHREAD_AUTO_VARS=	yes

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
