# $NetBSD: Makefile,v 1.2 2005/09/28 12:27:52 rillig Exp $

DISTNAME=	lighttpd-1.4.3
CATEGORIES=	www
MASTER_SITES=	http://www.lighttpd.net/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.lighttpd.net/
COMMENT=	Fast, light-footprint HTTP server

USE_LIBTOOL=		yes
SHLIBTOOL_OVERRIDE=	libtool

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/${PKGBASE}
CONFIGURE_ARGS+=	--with-pcre

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
PKG_SYSCONFSUBDIR=	${PKGBASE}

USE_PKGINSTALL=		yes
RCD_SCRIPTS=		lighttpd
CONF_FILES=		${EGDIR}/lighttpd.conf ${PKG_SYSCONFDIR}/lighttpd.conf

.include "options.mk"

.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}; for f in doc/*.css doc/*.dot doc/*.txt; do	\
		${INSTALL_DATA} $$f ${DOCDIR};				\
	done
	for f in AUTHORS COPYING ChangeLog NEWS README; do		\
		${INSTALL_DATA} ${WRKSRC}/$$f ${DOCDIR};		\
	done
	for f in lighttpd.conf rrdtool-graph.sh spawn-php.sh; do	\
		${INSTALL_DATA} ${WRKSRC}/doc/$$f ${EGDIR};		\
	done

.include "../../mk/bsd.pkg.mk"
