# $NetBSD: Makefile,v 1.24 2010/02/08 14:47:54 joerg Exp $

DISTNAME=	lighttpd-1.4.26
CATEGORIES=	www
MASTER_SITES=	http://download.lighttpd.net/lighttpd/releases-1.4.x/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.lighttpd.net/
COMMENT=	Fast, light-footprint HTTP server

#PATCHFILES=	fix-2147-in-1.4.x.patch
#PATCH_SITES=	http://redmine.lighttpd.net/attachments/download/1091/
#PATCH_DIST_STRIP.fix-2147-in-1.4.x.patch= -p1

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
