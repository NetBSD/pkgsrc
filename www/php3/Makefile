# $NetBSD: Makefile,v 1.31 2001/11/09 17:26:27 hubertf Exp $
#

DISTNAME=	php-${PHP_VERSION}
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.php.net/pub/distributions/
# This is needed because other pkgs .include this Makefile
DISTFILES+=	${DISTNAME}.tar.gz

MAINTAINER=	cjs@netbsd.org
HOMEPAGE=	http://www.php.net/
COMMENT=	PHP3 HTML-embedded programming language with database connectivity

BUILD_DEPENDS+=	perl>=${PERL5_REQD}:../../lang/perl5

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
DEPENDS+=	zlib-[0-9]*:../../devel/zlib
.endif

PHP_VERSION=	3.0.18

.if defined(BUILDING_EXTENSION_MODULE) || defined(BUILDING_SERVER_MODULE)
DEPENDS+=	php-${PHP_VERSION}:../../www/php3
DISTINFO_FILE=	${.CURDIR}/../../www/php3/distinfo
FILESDIR?=	${.CURDIR}/../../www/php3/files
PATCHDIR?=	${.CURDIR}/../../www/php3/patches
.endif

# Here we configure only for what NetBSD ships.  We add the rest via modules.
GNU_CONFIGURE=	# defined
CONFIGURE_ARGS+=--with-system-regex --without-gd \
		--with-gdbm=${PREFIX} \
		--with-yp --with-zlib --with-dbase --with-filepro \
		--with-config-file-path=${PREFIX}/etc \
		--with-exec-dir=${PREFIX}/libexec/php3 \
		--enable-track-vars --enable-force-cgi-redirect \
		--enable-discard-path --enable-memory-limit \
		--enable-sysvsem --enable-sysvshm
CONFIGURE_ENV+=	PERL_PATH=${PERL5}
CONFIGURE_ENV+=	PREFIX=${PREFIX}

.if !defined(BUILDING_EXTENSION_MODULE)
CPPFLAGS+=	-DPHP_INTERNAL_FUNCS

post-extract:
	@${CP} ${FILESDIR}/abstractions.c ${WRKSRC}

.if !defined(BUILDING_SERVER_MODULE)
post-build:
	@cd ${WRKSRC}/convertor && ${MAKE}

# The PHP includes are not easily detachable from the source tree in this
# release, so we extract the PHP sources with every module.
# This should improve in PHP 3.1 or 4.0.

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/php ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/convertor/convertor \
		${PREFIX}/bin/php2convert
	if [ ! -d ${PREFIX}/libexec/cgi-bin ]; then \
	  ${INSTALL_PROGRAM_DIR}  ${PREFIX}/libexec/cgi-bin ; fi
	${LN} -sf ../../bin/php ${PREFIX}/libexec/cgi-bin/php
	${INSTALL_DATA_DIR} ${PREFIX}/lib/php3
	${INSTALL_DATA_DIR} ${PREFIX}/share/php3
	${INSTALL_DATA} ${WRKSRC}/extra/icons/* ${PREFIX}/share/php3/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/php3
	${INSTALL_DATA} ${WRKSRC}/examples/README* ${WRKSRC}/examples/*.php3 \
		${PREFIX}/share/examples/php3/
	@${SED} s,@PREFIX@,${PREFIX}, ${FILESDIR}/php3.ini.example \
		> ${WRKDIR}/php3.ini.example
	${INSTALL_DATA} ${WRKDIR}/php3.ini.example ${PREFIX}/etc/
	@[ -f ${PREFIX}/etc/php3.ini ] || ${CP} ${PREFIX}/etc/php3.ini.example ${PREFIX}/etc/php3.ini
.endif
.endif

.include "../../databases/gdbm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
