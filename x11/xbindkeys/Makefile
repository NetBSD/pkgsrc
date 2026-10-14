# $NetBSD: Makefile,v 1.27 2026/10/14 05:43:23 wiz Exp $

PKGREVISION= 4
.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-tk

PTHREAD_AUTO_VARS=	yes

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
