# $NetBSD: Makefile,v 1.83 2001/11/21 15:44:23 jlam Exp $
#
# This pkg does not compile in mod_ssl, only the `mod_ssl EAPI' (a set of
# code hooks that allow mod_ssl to be compiled separately later, if desired).

DISTNAME=		apache_1.3.22
PKGNAME=		apache-1.3.22
CATEGORIES=		www
MASTER_SITES=		http://httpd.apache.org/dist/httpd/ \
			http://www.apache.de/dist/httpd/ \
			http://www.netbsd.org/images/logos/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			sitedrivenby.gif

MASTER_SITES+=		http://www.modssl.org/source/ \
			ftp://ftp.uni-trier.de/pub/unix/security/mod_ssl/source/
DISTFILES+=		${MODSSL_DISTNAME}${EXTRACT_SUFX}
MODSSL_DISTNAME=	mod_ssl-2.8.5-1.3.22
MODSSL_SRC=		${WRKDIR}/${MODSSL_DISTNAME}

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://httpd.apache.org/
COMMENT=		HTTP (Web) server

CONFLICTS=		apache-*modssl-[0-9]* apache6-[0-9]*

EXTRACT_ONLY=		${DISTFILES:N*.gif}
USE_BUILDLINK_ONLY=	YES
HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-layout="${WRKDIR}/config.layout:pkgsrc"
CONFIGURE_ARGS+=	--enable-module=most				\
			--enable-module=auth_db				\
			--disable-module=auth_dbm
CONFIGURE_ARGS+=	--enable-rule=EAPI				\
			--disable-module=ssl
CONFIGURE_ARGS+=	--with-perl=${PERL5}
CONFIGURE_ARGS+=	--with-port=80
CONFIGURE_ENV+=		OPTIM="${APACHE_CUSTOM_CFLAGS}"

.include "../../mk/bsd.prefs.mk"

APACHE_SYSCONFDIR?=	${CONFDIR}/httpd
BUILD_DEFS+=		APACHE_SYSCONFDIR
FILES_SUBST+=		APACHE_SYSCONFDIR=${APACHE_SYSCONFDIR}

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
CONFIGURE_ARGS+=	--enable-shared=define	# from mod_ssl pkg.addon
PLIST_SRC+=		${PKGDIR}/PLIST.shared
.else
CONFIGURE_ARGS+=	--disable-module=proxy
CONFIGURE_ARGS+=	--disable-shared=define
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

CONF_FILES=	${EGDIR}/httpd.conf.default ${APACHE_SYSCONFDIR}/httpd.conf
SUPPORT_FILES=	${EGDIR}/magic.default ${APACHE_SYSCONFDIR}/magic
SUPPORT_FILES+=	${EGDIR}/mime.types.default ${APACHE_SYSCONFDIR}/mime.types
RCD_SCRIPTS=	apache

MAKE_DIRS=		${APACHE_SYSCONFDIR}
OWN_DIRS=		${APACHE_SYSCONFDIR}/ssl.crl
OWN_DIRS+=		${APACHE_SYSCONFDIR}/ssl.crt
OWN_DIRS+=		${APACHE_SYSCONFDIR}/ssl.csr
OWN_DIRS+=		${APACHE_SYSCONFDIR}/ssl.key
OWN_DIRS+=		${APACHE_SYSCONFDIR}/ssl.prm
OWN_DIRS+=		/var/log/httpd
OWN_DIRS+=		/var/spool/httpd
OWN_DIRS_PERMS+=	/var/spool/httpd/proxy nobody nobody 0755

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
	cd ${WRKSRC} && ${TAIL} +160					\
		${MODSSL_SRC}/pkg.ssldoc/ssldoc.patch			\
		| ${PATCH} ${PATCH_ARGS}
	${FIND} ${WRKSRC} -name '*.orig' -print | ${XARGS} ${RM} -f

post-patch:
	cd ${WRKSRC}/src/support;					\
	${SED}	-e "s|@INSTALL@|"`${TYPE} ${INSTALL} | ${AWK} '{ print $$NF }'`" -c -o ${LIBOWN} -g ${LIBGRP}|" \
		apxs.pl > apxs.pl.sed;					\
	${MV} apxs.pl.sed apxs.pl

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
		${INSTALL_DATA} ${APACHE_SYSCONFDIR}/$${file}.default	\
			${PREFIX}/share/examples/httpd;			\
		${RM} -f ${APACHE_SYSCONFDIR}/$${file}.default;		\
	done
	${INSTALL_DATA} ${DISTDIR}/sitedrivenby.gif ${PREFIX}/share/httpd/htdocs
	${INSTALL_SCRIPT} ${WRKDIR}/apache.sh ${PREFIX}/etc/rc.d/apache
	${CHOWN} -R ${DOCOWN}:${DOCGRP} ${PREFIX}/share/httpd
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../textproc/expat/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
