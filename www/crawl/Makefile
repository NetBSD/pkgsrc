# $NetBSD: Makefile,v 1.25 2023/10/24 22:11:25 wiz Exp $

DISTNAME=	crawl-0.4
PKGREVISION=	14
CATEGORIES=	www
MASTER_SITES=	http://monkey.org/~provos/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://monkey.org/~provos/crawl/
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
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	cfg.h
SUBST_SED.path=		-e 's,crawl.conf,${PKG_SYSCONFDIR}/crawl.conf,g'
SUBST_MESSAGE.path=	Fixing hardcoded path.

.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
