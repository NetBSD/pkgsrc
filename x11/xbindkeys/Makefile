# $NetBSD: Makefile,v 1.21 2016/09/15 15:58:49 wiz Exp $

.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-tk

PTHREAD_AUTO_VARS=	yes

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
