# $NetBSD: Makefile,v 1.1.1.1 2000/10/25 13:28:41 jdolecek Exp $
#

DISTNAME=	php-4.0.1pl2
PKGNAME=	ap-${DISTNAME}
CATEGORIES=	www lang
# Note the http address is written this way by purpose, so that bsd.pkg.mk DTRT
MASTER_SITES=	http://www.php.net/do_download.php?source_site=www.php.net&download_file= \
		ftp://ftp.php.net/pub/distributions/

MAINTAINER=	jdolecek@netbsd.org
HOMEPAGE=	http://www.php.net/

DEPENDS+=	apache-1.3.*:../../www/apache
DEPENDS+=	gdbm>=1.7.3:../../databases/gdbm

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
DEPENDS+=	zlib-*:../../devel/zlib
.endif

USE_PERL5=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

# Here we configure only for what NetBSD ships.  We add the rest via modules.
# The --without-mysql is there to avoid using the bundled MySQL client library.
GNU_CONFIGURE=	# defined
CONFIGURE_ARGS+=--with-system-regex --without-gd \
		--with-gdbm=${PREFIX} \
		--with-yp --with-zlib --with-dbase --with-filepro \
		--with-config-file-path=${PREFIX}/etc		\
		--with-exec-dir=${PREFIX}/libexec/php4		\
		--enable-track-vars --enable-force-cgi-redirect \
		--enable-discard-path --enable-memory-limit	\
		--enable-sysvsem --enable-sysvshm		\
		--enable-wddx --without-mysql			\
		--with-apxs=${LOCALBASE}/sbin/apxs
CONFIGURE_ENV+=	PERL_PATH=${PERL5}

MESSAGE_FILE=${WRKDIR}/.MESSAGE
pre-install:
	${SED} -e "s^%PREFIX%^$$PREFIX^" ${PKGDIR}/MESSAGE > ${MESSAGE_FILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/libphp4.so \
			${PREFIX}/lib/httpd/mod_php4.so
	${INSTALL_DATA} ${WRKSRC}/php.ini-dist ${PREFIX}/etc/
	${INSTALL_DATA} ${WRKSRC}/php.ini-optimized ${PREFIX}/etc/
	${INSTALL_DATA_DIR} ${PREFIX}/share/php4
	${INSTALL_DATA} ${WRKSRC}/php4.gif ${PREFIX}/share/php4/

.include "../../mk/bsd.pkg.mk"
