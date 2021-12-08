# $NetBSD: Makefile,v 1.24 2021/12/08 16:07:15 adam Exp $

PKGREVISION= 1
.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-tk

PTHREAD_AUTO_VARS=	yes

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
