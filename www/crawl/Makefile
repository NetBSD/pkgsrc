# $NetBSD: Makefile,v 1.8 2007/04/25 16:39:41 tnn Exp $

DISTNAME=	crawl-0.4
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://monkey.org/~provos/

MAINTAINER=	peter@pointless.nl
HOMEPAGE=	http://monkey.org/~provos/crawl/
COMMENT=	Small and efficient HTTP crawler

GNU_CONFIGURE=	yes
USE_DB185=	yes

CONF_FILES=	${PREFIX}/share/examples/${PKGBASE}/crawl.conf ${PKG_SYSCONFDIR}/crawl.conf

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/crawl.conf ${PREFIX}/share/examples/${PKGBASE}/crawl.conf

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	cfg.h
SUBST_SED.path=		-e 's,crawl.conf,${PKG_SYSCONFDIR}/crawl.conf,g'
SUBST_MESSAGE.path=	Fixing hardcoded path.

.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
