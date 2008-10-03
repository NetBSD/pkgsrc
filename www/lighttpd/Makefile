# $NetBSD: Makefile,v 1.21.4.1 2008/10/03 11:12:18 tron Exp $

DISTNAME=	lighttpd-1.4.20
CATEGORIES=	www
MASTER_SITES=	http://www.lighttpd.net/download/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.lighttpd.net/
COMMENT=	Fast, light-footprint HTTP server

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
SHLIBTOOL_OVERRIDE=	# empty

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/${PKGBASE}
CONFIGURE_ARGS+=	--with-pcre

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
PKG_SYSCONFSUBDIR=	${PKGBASE}

RCD_SCRIPTS=		lighttpd
CONF_FILES=		${EGDIR}/lighttpd.conf ${PKG_SYSCONFDIR}/lighttpd.conf

INSTALLATION_DIRS=	${DOCDIR} ${EGDIR}

.include "options.mk"

.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"

post-install:
	cd ${WRKSRC}; for f in doc/*.css doc/*.dot doc/*.txt; do	\
		${INSTALL_DATA} $$f ${DESTDIR}${DOCDIR};		\
	done
	for f in AUTHORS COPYING ChangeLog NEWS README; do		\
		${INSTALL_DATA} ${WRKSRC}/$$f ${DESTDIR}${DOCDIR};	\
	done
	for f in lighttpd.conf rrdtool-graph.sh spawn-php.sh; do	\
		${INSTALL_DATA} ${WRKSRC}/doc/$$f ${DESTDIR}${EGDIR};	\
	done

.include "../../mk/bsd.pkg.mk"
