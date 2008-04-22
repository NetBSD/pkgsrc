# $NetBSD: Makefile,v 1.10 2008/04/22 18:06:09 tnn Exp $

DISTNAME=	crawl-0.4
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://monkey.org/~provos/

MAINTAINER=	pkgsrc-users@NetBSD.org
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
