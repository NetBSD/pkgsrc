# $NetBSD: Makefile,v 1.20 2014/02/12 23:18:44 tron Exp $

DISTNAME=	crawl-0.4
PKGREVISION=	11
CATEGORIES=	www
MASTER_SITES=	http://monkey.org/~provos/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://monkey.org/~provos/crawl/
COMMENT=	Small and efficient HTTP crawler

GNU_CONFIGURE=	yes
USE_DB185=	yes

# BDB detection is not sufficient, specify manually instead.
CONFIGURE_ARGS+=	--with-db=yes
CONFIGURE_ENV+=		DBLIB=${BDB_LIBS:Q}
CPPFLAGS+=		-DHAVE_DB_185_H

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
