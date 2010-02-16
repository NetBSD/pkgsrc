# $NetBSD: Makefile,v 1.15 2010/02/16 18:11:52 joerg Exp $

DISTNAME=	crawl-0.4
PKGREVISION=	8
CATEGORIES=	www
MASTER_SITES=	http://monkey.org/~provos/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://monkey.org/~provos/crawl/
COMMENT=	Small and efficient HTTP crawler

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_DB185=	yes

CONF_FILES=	${PREFIX}/share/examples/crawl/crawl.conf ${PKG_SYSCONFDIR}/crawl.conf

INSTALLATION_DIRS+=	share/examples/crawl

post-install:
	${INSTALL_DATA} ${WRKSRC}/crawl.conf ${DESTDIR}${PREFIX}/share/examples/crawl/crawl.conf

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	cfg.h
SUBST_SED.path=		-e 's,crawl.conf,${PKG_SYSCONFDIR}/crawl.conf,g'
SUBST_MESSAGE.path=	Fixing hardcoded path.

.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
