# $NetBSD: Makefile,v 1.26 2022/10/26 10:32:08 wiz Exp $

PKGREVISION= 3
.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-tk

PTHREAD_AUTO_VARS=	yes

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
