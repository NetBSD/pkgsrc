# $NetBSD: Makefile,v 1.22 2020/03/08 16:51:51 wiz Exp $

PKGREVISION= 1
.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-tk

PTHREAD_AUTO_VARS=	yes

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
