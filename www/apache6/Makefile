# $NetBSD: Makefile,v 1.47 2001/11/29 01:12:51 hubertf Exp $
#
# This package does not compile in mod_ssl support hooks, as it conflicts
# with IPv6-enable patch.
#
# IPv6-enable patch conflicts with third-party modules anyway, due to
# sanity fixes in apache module API (for example, avoid u_long for IPv4 addrs)
#

DISTNAME=		apache_1.3.22
PKGNAME=		apache6-1.3.22
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		http://httpd.apache.org/dist/httpd/ \
			http://www.apache.de/dist/httpd/ \
			http://www.netbsd.org/images/logos/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			sitedrivenby.gif

MASTER_SITES+=		ftp://ftp.piuha.net/pub/misc/
DISTFILES+=		${IPV6_PATCH}
IPV6_PATCH=		apache-1.3.22-v6-20011123.diff.gz

MAINTAINER=		itojun@netbsd.org
HOMEPAGE=		http://httpd.apache.org/
COMMENT=		HTTP (Web) server with IPv6 support

CONFLICTS=		apache-[0-9]* apache-*modssl-[0-9]* apache6-[0-9]*

EXTRACT_ONLY=		${DISTFILES:N*.gif:N*.diff.gz}
USE_BUILDLINK_ONLY=	YES
HAS_CONFIGURE=		YES
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

PKG_SYSCONFSUBDIR?=	httpd

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

# Note that there is NO static compile module hook here.  This is intentional.
# Under Apache 1.3, modules can be compiled to link dynamically to the server
# using the "apxs" program.  See apxs(8).

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

# On NetBSD ELF platforms, we need to link libgcc.a whole-archive so that
# certain symbols from the C++ implementation (__get_eh_context, etc.)
# referenced by DSOs written in C++ will resolve correctly.
#
.if (${OPSYS} == "NetBSD") && (${OBJECT_FMT} == "ELF")
LINK_LIBGCC_LDFLAGS=	-Wl,--whole-archive -lgcc -Wl,--no-whole-archive
MAKE_ENV+=		LINK_LIBGCC_LDFLAGS="${LINK_LIBGCC_LDFLAGS}"
.endif

.if (${OPSYS} == "SunOS")
LDFLAGS+=		-Wl,-R/usr/ucblib -L/usr/ucblib
CONFIGURE_ENV+=		INCLUDES="-I${BUILDLINK_DIR}/include/db2"
CONFIGURE_ENV+=		LIBS="-ldbm -ldb2"
BUILDLINK_DEPENDS.db=	db>=2.7.7
.include "../../databases/db/buildlink.mk"
.endif

BUILD_DEFS+=		APACHE_CUSTOM_CFLAGS
BUILD_DEFS+=		APACHE_PERF_TUNING
BUILD_DEFS+=		APACHE_SUEXEC

EGDIR=		${PREFIX}/share/examples/httpd

CONF_FILES=	${EGDIR}/httpd.conf.default ${PKG_SYSCONFDIR}/httpd.conf
SUPPORT_FILES=	${EGDIR}/magic.default ${PKG_SYSCONFDIR}/magic
SUPPORT_FILES+=	${EGDIR}/mime.types.default ${PKG_SYSCONFDIR}/mime.types
RCD_SCRIPTS=	apache

OWN_DIRS=		/var/log/httpd
OWN_DIRS+=		/var/spool/httpd
OWN_DIRS_PERMS+=	/var/spool/httpd/proxy nobody nobody 0755

pre-patch:
	${FIND} ${WRKSRC} -name '*.orig' -print | ${XARGS} ${RM} -f

post-patch:
	cd ${WRKSRC}/src/support;					\
	${SED}	-e "s|@INSTALL@|"`${TYPE} ${INSTALL} | ${AWK} '{ print $$NF }'`" -c -o ${LIBOWN} -g ${LIBGRP}|" \
		apxs.pl > apxs.pl.sed;					\
	${MV} apxs.pl.sed apxs.pl

	for file in ${IPV6_PATCH}; do					\
		${GZCAT} ${_DISTDIR}/$${file} |				\
		    ${PATCH} ${PATCH_DIST_ARGS}				\
		    || ( ${ECHO} "Patch $${file} failed" ; exit 1 ) ;	\
	done
	${CHMOD} +x ${CONFIGURE_SCRIPT}
	cp ${WRKSRC}/conf/httpd.conf-dist ${WRKSRC}/conf/httpd.conf-dist-
	${SED}	-e "s|#Listen ::|Listen ::|"				\
		-e "s|#Listen 0.0.0.0|Listen 0.0.0.0|"			\
		${WRKSRC}/conf/httpd.conf-dist-				\
		> ${WRKSRC}/conf/httpd.conf-dist

pre-configure:
	${SED} ${FILES_SUBST_SED}					\
		${FILESDIR}/config.layout > ${WRKDIR}/config.layout

pre-install:
	${FIND} ${WRKSRC}/htdocs -name '*.orig' -print | ${XARGS} ${RM} -f
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/apache.sh > ${WRKDIR}/apache.sh

post-install:
.if !defined(NOPIC)
	cd ${PREFIX}/lib/httpd; ${MV} libproxy.so mod_proxy.so
.endif
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/httpd
	for file in httpd.conf magic mime.types; do			\
		${INSTALL_DATA} ${PKG_SYSCONFDIR}/$${file}.default	\
			${PREFIX}/share/examples/httpd;			\
		${RM} -f ${PKG_SYSCONFDIR}/$${file}.default;		\
	done
	${INSTALL_DATA} ${DISTDIR}/sitedrivenby.gif ${PREFIX}/share/httpd/htdocs
	${INSTALL_SCRIPT} ${WRKDIR}/apache.sh ${PREFIX}/etc/rc.d/apache
	${CHOWN} -R ${DOCOWN}:${DOCGRP} ${PREFIX}/share/httpd
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../textproc/expat/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
