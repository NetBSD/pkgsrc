# $NetBSD: Makefile,v 1.59 2001/02/07 09:52:45 tron Exp $
#
# The fourth number in the PKGNAME version indicates a NetBSD pkg revision
# (to indicate changes in the shipped third party patches such as the mod_ssl
# EAPI when there has been no change to the Apache version number).
#
# This pkg does not compile in mod_ssl, only the `mod_ssl EAPI' (a set of
# code hooks that allow mod_ssl to be compiled separately later, if desired).

DISTNAME=		apache_1.3.17
PKGNAME=		apache-1.3.17.1
CATEGORIES=		www
MASTER_SITES=		http://httpd.apache.org/dist/ \
			http://www.apache.de/dist/ \
			http://www.modssl.org/source/ \
			ftp://ftp.uni-trier.de/pub/unix/security/mod_ssl/ \
			http://www.netbsd.org/images/logos/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			${SSL_DISTNAME}${EXTRACT_SUFX} \
			sitedrivenby.gif

PATCH_SITES=		http://httpd.apache.org/dist/
PATCHFILES=		apache_1.3.17-fix.diff

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://httpd.apache.org/

CONFLICTS=		apache-*modssl-* apache6-*

SSL_DISTNAME=		mod_ssl-2.8.0-1.3.17

EXTRACT_ONLY=		${DISTFILES:N*.gif}
HAS_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--prefix=${PREFIX}				\
			--sbindir=${PREFIX}/sbin			\
			--libexecdir=${PREFIX}/lib/httpd		\
			--sysconfdir=${PREFIX}/etc/httpd		\
			--datadir=${PREFIX}/share/httpd			\
			--cgidir=${PREFIX}/libexec/cgi-bin		\
			--includedir=${PREFIX}/include/httpd		\
			--runtimedir=/var/run				\
			--logfiledir=/var/log/httpd			\
			--proxycachedir=/var/spool/httpd/proxy
CONFIGURE_ARGS+=	--enable-rule=EAPI				\
			--enable-module=most				\
			--disable-module=ssl				\
			--enable-module=auth_db				\
			--disable-module=auth_dbm
CONFIGURE_ARGS+=	--with-perl=${PERL5}
CONFIGURE_ARGS+=	--with-port=80
CONFIGURE_ENV+=		OPTIM="${OPTIM}"

.include "../../mk/bsd.prefs.mk"

.if defined(APACHE_SUEXEC) && ${APACHE_SUEXEC} == YES
APACHE_USER?=		www
SUEXEC_PATH=		/bin:/usr/bin:${PREFIX}/bin:/usr/local/bin
CONFIGURE_ARGS+=	--enable-suexec 				\
			--suexec-caller=${APACHE_USER}			\
			--suexec-safepath='${SUEXEC_PATH}'
PLIST_SRC=		${PKGDIR}/PLIST.suexec
BUILD_DEFS+=		APACHE_USER
.endif

.if !defined(NOPIC)
CONFIGURE_ARGS+=	--enable-module=so	# requires dlopen()
CONFIGURE_ARGS+=	--enable-shared=proxy
PLIST_SRC+=		${PKGDIR}/PLIST.shared
.else
CONFIGURE_ARGS+=	--disable-module=proxy
.endif

PLIST_SRC+=		${PKGDIR}/PLIST

.if defined(APACHE_PERF_TUNING) && ${APACHE_PERF_TUNING} == YES
OPTIM+=			-DBUFFERED_LOGS
CFLAGS+=		-O6 -fomit-frame-pointer -fexpensive-optimizations
.endif

.if (${OPSYS} == "SunOS")
DEPENDS+=		db-2.7.7:../../databases/db
LDFLAGS+=		-Wl,-R/usr/ucblib -L/usr/ucblib			\
			-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib
CONFIGURE_ENV+=		INCLUDES="-I${LOCALBASE}/include/db2"
CONFIGURE_ENV+=		LIBS="-ldbm -ldb2"
.endif

BUILD_DEFS+=		APACHE_PERF_TUNING APACHE_SUEXEC

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

# Note that there is NO static compile module hook here.  This is intentional.
# Under Apache 1.3, modules can be compiled to link dynamically to the server
# using the "apxs" program.  See apxs(8).

post-extract:
	${CP} ${FILESDIR}/ap_include_extern.h ${WRKSRC}/src/include
	${CP} ${WRKDIR}/${SSL_DISTNAME}/pkg.eapi/*.c ${WRKSRC}/src/ap
	${CP} ${WRKDIR}/${SSL_DISTNAME}/pkg.eapi/*.h ${WRKSRC}/src/include

pre-patch:
	cd ${WRKSRC} && ${CAT}						\
		${WRKDIR}/${SSL_DISTNAME}/pkg.eapi/eapi.patch		\
		${WRKDIR}/${SSL_DISTNAME}/pkg.sslcfg/sslcfg.patch	\
		${WRKDIR}/${SSL_DISTNAME}/pkg.sslmod/sslmod.patch	\
		${WRKDIR}/${SSL_DISTNAME}/pkg.sslsup/sslsup.patch	\
		| ${PATCH} ${PATCH_ARGS}
	cd ${WRKSRC} && ${TAIL} +154					\
		${WRKDIR}/${SSL_DISTNAME}/pkg.ssldoc/ssldoc.patch	\
		| ${PATCH} ${PATCH_ARGS}
	${FIND} ${WRKSRC} -name '*.orig' -exec ${RM} -f {} \;

post-build:
	${SED}	-e "s,@PREFIX@,${PREFIX},g"				\
		${FILESDIR}/apache.sh > ${WRKDIR}/apache.sh

pre-install:
	${FIND} ${WRKSRC}/htdocs -name '*.orig' -exec ${RM} -f {} \;
	${SED}	-e "s|@CAT@|${CAT}|g"					\
		-e "s|@RM@|${RM}|g"					\
		-e "s|@RMDIR@|${RMDIR}|g"				\
		-e "s|@TRUE@|${TRUE}|g"					\
		${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}	-e "s|@CAT@|${CAT}|g"					\
		-e "s|@CHMOD@|${CHMOD}|g"				\
		-e "s|@CHOWN@|${CHOWN}|g"				\
		-e "s|@CP@|${CP}|g"					\
		-e "s|@MKDIR@|${MKDIR}|g"				\
		${PKGDIR}/INSTALL > ${INSTALL_FILE}

post-install:
.if !defined(NOPIC)
	cd ${PREFIX}/lib/httpd; ${MV} libproxy.so mod_proxy.so
.endif
	${INSTALL_DATA} ${DISTDIR}/sitedrivenby.gif ${PREFIX}/share/httpd/htdocs
	${INSTALL_SCRIPT} ${WRKDIR}/apache.sh ${PREFIX}/etc/rc.d/apache
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
