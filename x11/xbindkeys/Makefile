# $NetBSD: Makefile,v 1.25 2022/03/07 22:59:50 wiz Exp $

PKGREVISION= 2
.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-tk

PTHREAD_AUTO_VARS=	yes

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
