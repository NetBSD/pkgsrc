# $NetBSD: Makefile,v 1.20 2016/09/15 14:32:41 wiz Exp $
#

.include "Makefile.common"

PKGREVISION=		5

CONFIGURE_ARGS+=	--disable-tk

PTHREAD_AUTO_VARS=	yes

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
