# $NetBSD: Makefile,v 1.31 2001/05/18 06:01:36 jlam Exp $
#
# This package does not compile in mod_ssl support hooks, as it conflicts
# with IPv6-enable patch.
#
# IPv6-enable patch conflicts with third-party modules anyway, due to
# sanity fixes in apache module API (for example, avoid u_long for IPv4 addrs)
#

DISTNAME=		apache_1.3.19
PKGNAME=		apache6-1.3.19
CATEGORIES=		www
MASTER_SITES=		http://httpd.apache.org/dist/httpd/ \
			http://www.apache.de/dist/httpd/ \
			http://www.netbsd.org/images/logos/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			sitedrivenby.gif

MASTER_SITES+=		ftp://ftp.kame.net/pub/kame/misc/
DISTFILES+=		${IPV6_PATCH}
IPV6_PATCH=		apache-1.3.19-v6-20010301a.diff.gz
PATCH_DIST_STRIP=	-p1	# IPv6 patch needs -p1

MAINTAINER=		itojun@netbsd.org
HOMEPAGE=		http://httpd.apache.org/
COMMENT=		HTTP (Web) server with IPv6 support

CONFLICTS=		apache-* apache-*modssl-* apache6-*

EXTRACT_ONLY=		${DISTFILES:N*.gif:N*.diff.gz}
HAS_CONFIGURE=		# defined
CONFIGURE_SCRIPT=	${WRKSRC}/configure.v6
CONFIGURE_ARGS+=	--with-layout="${WRKDIR}/config.layout:pkgsrc"
CONFIGURE_ARGS+=	--enable-module=most				\
			--enable-module=auth_db				\
			--disable-module=auth_dbm
CONFIGURE_ARGS+=	--with-perl=${PERL5}
CONFIGURE_ARGS+=	--with-port=80
CONFIGURE_ENV+=		OPTIM="${APACHE_CUSTOM_CFLAGS}"

BUILD_DEFS+=		USE_INET6

.include "../../mk/bsd.prefs.mk"

.if !defined(USE_INET6) || ${USE_INET6} != YES
IGNORE=			"IPv6 only build"
.endif

APACHE_SYSCONFDIR?=	${LOCALBASE}/etc/httpd
BUILD_DEFS+=		APACHE_SYSCONFDIR

.if defined(APACHE_SUEXEC) && ${APACHE_SUEXEC} == YES
APACHE_USER?=		www
APACHE_SUEXEC_DOCROOT?=	${LOCALBASE}/share/httpd/htdocs
SUEXEC_PATH=		/bin:/usr/bin:${PREFIX}/bin:/usr/local/bin
CONFIGURE_ARGS+=	--enable-suexec 				\
			--suexec-caller=${APACHE_USER}			\
			--suexec-safepath='${SUEXEC_PATH}'		\
			--suexec-docroot=${APACHE_SUEXEC_DOCROOT}
PLIST_SRC=		${PKGDIR}/PLIST.suexec
BUILD_DEFS+=		APACHE_USER APACHE_SUEXEC_DOCROOT
.endif

.if !defined(NOPIC)
CONFIGURE_ARGS+=	--enable-module=so	# requires dlopen()
CONFIGURE_ARGS+=	--enable-shared=proxy
PLIST_SRC+=		${PKGDIR}/PLIST.shared
.else
CONFIGURE_ARGS+=	--disable-module=proxy
.endif

PLIST_SRC+=		${PKGDIR}/PLIST

APACHE_CUSTOM_CFLAGS?=	# empty

.if defined(APACHE_PERF_TUNING) && ${APACHE_PERF_TUNING} == YES
APACHE_CUSTOM_CFLAGS+=	-DBUFFERED_LOGS
APACHE_CUSTOM_CFLAGS+=	-O6 -fomit-frame-pointer -fexpensive-optimizations
.endif

.if (${OPSYS} == "SunOS")
DEPENDS+=		db-2.7.7:../../databases/db
LDFLAGS+=		-Wl,-R/usr/ucblib -L/usr/ucblib			\
			-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib
CONFIGURE_ENV+=		INCLUDES="-I${LOCALBASE}/include/db2"
CONFIGURE_ENV+=		LIBS="-ldbm -ldb2"
.endif

BUILD_DEFS+=		APACHE_CUSTOM_CFLAGS
BUILD_DEFS+=		APACHE_PERF_TUNING
BUILD_DEFS+=		APACHE_SUEXEC

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

# Note that there is NO static compile module hook here.  This is intentional.
# Under Apache 1.3, modules can be compiled to link dynamically to the server
# using the "apxs" program.  See apxs(8).

pre-patch:
	${FIND} ${WRKSRC} -name '*.orig' -exec ${RM} -f {} \;

post-patch:
	for file in ${IPV6_PATCH}; do					\
		${GZCAT} ${_DISTDIR}/$${file} |				\
		    ${PATCH} ${PATCH_DIST_ARGS}				\
		    || ( ${ECHO} "Patch $${file} failed" ; exit 1 ) ;	\
	done
	${CHMOD} +x ${CONFIGURE_SCRIPT}

pre-configure:
	${SED}	-e "s|@PREFIX@|${PREFIX}|g"				\
		-e "s|@APACHE_SYSCONFDIR@|${APACHE_SYSCONFDIR}|g"	\
		${FILESDIR}/config.layout > ${WRKDIR}/config.layout

pre-install:
	${FIND} ${WRKSRC}/htdocs -name '*.orig' -exec ${RM} -f {} \;
	${SED}	-e "s|@PREFIX@|${PREFIX}|g"				\
		-e "s|@APACHE_SYSCONFDIR@|${APACHE_SYSCONFDIR}|g"	\
		${FILESDIR}/apache.sh > ${WRKDIR}/apache.sh
	${SED}	-e "s|@CAT@|${CAT}|g"					\
		-e "s|@RM@|${RM}|g"					\
		-e "s|@RMDIR@|${RMDIR}|g"				\
		-e "s|@TRUE@|${TRUE}|g"					\
		-e "s|@APACHE_SYSCONFDIR@|${APACHE_SYSCONFDIR}|g"	\
		${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}	-e "s|@CAT@|${CAT}|g"					\
		-e "s|@CHMOD@|${CHMOD}|g"				\
		-e "s|@CHOWN@|${CHOWN}|g"				\
		-e "s|@CP@|${CP}|g"					\
		-e "s|@MKDIR@|${MKDIR}|g"				\
		-e "s|@APACHE_SYSCONFDIR@|${APACHE_SYSCONFDIR}|g"	\
		${PKGDIR}/INSTALL > ${INSTALL_FILE}

post-install:
.if !defined(NOPIC)
	cd ${PREFIX}/lib/httpd; ${MV} libproxy.so mod_proxy.so
.endif
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/httpd
	for i in httpd.conf magic mime.types; do			\
		${INSTALL_DATA} ${APACHE_SYSCONFDIR}/$$i.default	\
			${PREFIX}/share/examples/httpd;			\
		${RM} -f ${APACHE_SYSCONFDIR}/$$i.default;		\
	done
	${INSTALL_DATA} ${DISTDIR}/sitedrivenby.gif ${PREFIX}/share/httpd/htdocs
	${INSTALL_SCRIPT} ${WRKDIR}/apache.sh ${PREFIX}/etc/rc.d/apache
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
