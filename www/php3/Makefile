# $NetBSD: Makefile,v 1.3 1999/05/03 19:45:43 tv Exp $
#

DISTNAME=	php-${PHP_VERSION}
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.php.net/pub/distributions/

MAINTAINER=	cjs@netbsd.org
HOMEPAGE=	http://www.php.net/

# This is needed because other pkgs .include this Makefile
DISTFILES+=	${DISTNAME}.tar.gz
PHP_VERSION=	3.0.7

.if defined(BUILDING_EXTENSION_MODULE) || defined(BUILDING_SERVER_MODULE)
DEPENDS+=	php-${PHP_VERSION}:../../www/php3
.endif

.if !defined(BUILDING_EXTENSION_MODULE)
# Here we configure only for what NetBSD ships.  We add the rest via modules.
CONFIGURE_ARGS+=--with-system-regex --without-gd \
		--with-yp --with-zlib --with-dbase --with-filepro \
		--with-config-file-path=${PREFIX}/etc \
		--with-exec-dir=${PREFIX}/libexec/php3 \
		--enable-track-vars --enable-force-cgi-redirect \
		--enable-discard-path --enable-memory-limit \
		--enable-sysvsem --enable-sysvshm

GNU_CONFIGURE=  YES
LDFLAGS=	-Wl,-R${PREFIX}/lib/php3
CONFIGURE_ENV=	CPPFLAGS="-DPHP_INTERNAL_FUNCS"

post-extract:
	@${CP} ${FILESDIR}/abstractions.c ${WRKSRC}

.if !defined(BUILDING_SERVER_MODULE)
post-build:
	@cd ${WRKSRC}/convertor && ${MAKE}

# The PHP includes are not easily detachable from the source tree in this
# release, so we extract the PHP sources with every module, and only install
# config.h so that `./configure' need not be run every time.
# This should improve in PHP 3.1 or 4.0.

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/php3 ${PREFIX}/include/php3
	cd ${WRKSRC} && \
		${INSTALL_DATA} config.h ${PREFIX}/include/php3/
	${INSTALL_PROGRAM} ${WRKSRC}/php ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/convertor/convertor \
		${PREFIX}/bin/php2convert
	${LN} -sf ${PREFIX}/bin/php ${PREFIX}/libexec/cgi-bin/php
	cd ${WRKSRC}/dbase && \
		${INSTALL_PROGRAM} dbfadd dbfcreat dbfdel dbfget dbflst \
			dbfndx dbfpack dbftst ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/dbase/dbfscan ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/php3
	${INSTALL_DATA} ${WRKSRC}/extra/icons/* ${PREFIX}/share/php3/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/php3
	${INSTALL_DATA} ${WRKSRC}/examples/README* ${WRKSRC}/examples/*.php3 \
		${PREFIX}/share/examples/php3/
.endif
.endif

.include "../../mk/bsd.pkg.mk"
