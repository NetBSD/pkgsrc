# $NetBSD: Makefile,v 1.67 2001/04/29 21:21:13 jlam Exp $
#
# This pkg does not compile in mod_ssl, only the `mod_ssl EAPI' (a set of
# code hooks that allow mod_ssl to be compiled separately later, if desired).

DISTNAME=		apache_1.3.19
PKGNAME=		apache-1.3.19nb1
CATEGORIES=		www
MASTER_SITES=		http://httpd.apache.org/dist/httpd/ \
			http://www.apache.de/dist/httpd/ \
			http://www.netbsd.org/images/logos/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			sitedrivenby.gif

MASTER_SITES+=		http://www.modssl.org/source/ \
			ftp://ftp.uni-trier.de/pub/unix/security/mod_ssl/source/
DISTFILES+=		${MODSSL_DISTNAME}${EXTRACT_SUFX}
MODSSL_DISTNAME=	mod_ssl-2.8.2-1.3.19
MODSSL_SRC=		${WRKDIR}/${MODSSL_DISTNAME}

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://httpd.apache.org/
COMMENT=		HTTP (Web) server

CONFLICTS=		apache-*modssl-* apache6-*

EXTRACT_ONLY=		${DISTFILES:N*.gif}
HAS_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-layout="${WRKDIR}/config.layout:pkgsrc"
CONFIGURE_ARGS+=	--enable-module=most				\
			--enable-module=auth_db				\
			--disable-module=auth_dbm
CONFIGURE_ARGS+=	--enable-rule=EAPI				\
			--disable-module=ssl
CONFIGURE_ARGS+=	--with-perl=${PERL5}
CONFIGURE_ARGS+=	--with-port=80
CONFIGURE_ENV+=		OPTIM="${OPTIM}"

.include "../../mk/bsd.prefs.mk"

APACHE_SYSCONFDIR?=	${LOCALBASE}/etc/httpd
BUILD_DEFS+=		APACHE_SYSCONFDIR

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
CONFIGURE_ARGS+=	--enable-shared=define	# from mod_ssl pkg.addon
PLIST_SRC+=		${PKGDIR}/PLIST.shared
.else
CONFIGURE_ARGS+=	--disable-module=proxy
CONFIGURE_ARGS+=	--disable-shared=define
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
	${CP} ${MODSSL_SRC}/pkg.addon/*.c ${WRKSRC}/src/modules/extra
	${CP} ${MODSSL_SRC}/pkg.addon/*.html ${WRKSRC}/htdocs/manual/mod
	${CP} ${MODSSL_SRC}/pkg.eapi/*.c ${WRKSRC}/src/ap
	${CP} ${MODSSL_SRC}/pkg.eapi/*.h ${WRKSRC}/src/include

pre-patch:
	cd ${WRKSRC} && ${CAT}						\
		${MODSSL_SRC}/pkg.addon/addon.patch			\
		${MODSSL_SRC}/pkg.eapi/eapi.patch			\
		${MODSSL_SRC}/pkg.sslcfg/sslcfg.patch			\
		${MODSSL_SRC}/pkg.sslmod/sslmod.patch			\
		${MODSSL_SRC}/pkg.sslsup/sslsup.patch			\
		| ${PATCH} ${PATCH_ARGS}
	cd ${WRKSRC} && ${TAIL} +154					\
		${MODSSL_SRC}/pkg.ssldoc/ssldoc.patch			\
		| ${PATCH} ${PATCH_ARGS}
	${FIND} ${WRKSRC} -name '*.orig' -exec ${RM} -f {} \;

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
