# $NetBSD: Makefile,v 1.105 2002/09/19 09:04:28 jlam Exp $
#
# This pkg does not compile in mod_ssl, only the `mod_ssl EAPI' (a set of
# code hooks that allow mod_ssl to be compiled separately later, if desired).

DISTNAME=		apache_${APACHE_VERSION}
PKGNAME=		apache-${APACHE_VERSION}
APACHE_VERSION=		1.3.26
PKGREVISION=		4
CATEGORIES=		www
MASTER_SITES=		http://httpd.apache.org/dist/httpd/ \
			http://www.apache.de/dist/httpd/
# This must be defined, before it may be referred to on the LHS.
EXTRACT_SUFX=		.tar.gz

APACHE_DIST=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES=		${APACHE_DIST}

NETBSD_LOGO=		sitedrivenby.gif
SITES_${NETBSD_LOGO}=	http://www.netbsd.org/images/logos/
DISTFILES+=		${NETBSD_LOGO}

MODSSL_VERSION=		2.8.10
MODSSL_DISTNAME=	mod_ssl-${MODSSL_VERSION}-${APACHE_VERSION}
MODSSL_DIST=		${MODSSL_DISTNAME}${EXTRACT_SUFX}
MODSSL_SRC=		${WRKDIR}/${MODSSL_DISTNAME}
SITES_${MODSSL_DIST}=	http://www.modssl.org/source/ \
			ftp://ftp.pca.dfn.de/pub/tools/net/mod_ssl/source/ \
			ftp://ftp.funet.fi/pub/crypt/cryptography/libs/modssl/source/
DISTFILES+=		${MODSSL_DIST}

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://httpd.apache.org/
COMMENT=		Apache HTTP (Web) server

CONFLICTS=		apache-*ssl-[0-9]* apache6-[0-9]*

EXTRACT_ONLY=		${DISTFILES:N*.gif}
USE_BUILDLINK2=		YES
HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-layout="${WRKDIR}/config.layout:pkgsrc"
CONFIGURE_ARGS+=	--enable-module=most				\
			--enable-module=auth_db				\
			--disable-module=auth_dbm
CONFIGURE_ARGS+=	--enable-rule=EAPI				\
			--disable-module=ssl
CONFIGURE_ARGS+=	--without-confadjust
CONFIGURE_ARGS+=	--with-perl=${PERL5}
CONFIGURE_ARGS+=	--with-port=80
CONFIGURE_ENV+=		OPTIM="${APACHE_CUSTOM_CFLAGS}"
CONFIGURE_ENV+=		EAPI_MM="${BUILDLINK_PREFIX.libmm}"
CONFIGURE_ENV+=		BINOWN=${BINOWN} BINGRP=${BINGRP}

.include "../../mk/bsd.prefs.mk"

.if empty(STRIPFLAG)
CONFIGURE_ARGS+=	--without-execstrip
.endif

PKG_SYSCONFSUBDIR?=	httpd

APACHE_USER?=		www
APACHE_GROUP?=		www
BUILD_DEFS+=		APACHE_USER APACHE_GROUP

CONFIGURE_ARGS+=	--server-uid=${APACHE_USER}
CONFIGURE_ARGS+=	--server-gid=${APACHE_GROUP}

.if defined(APACHE_SUEXEC) && ${APACHE_SUEXEC} == YES
APACHE_SUEXEC_DOCROOT?=	${PREFIX}/share/httpd/htdocs
APACHE_SUEXEC_PATH=	/bin:/usr/bin:${PREFIX}/bin:/usr/local/bin
APACHE_SUEXEC_CONFIGURE_ARGS+=						\
			--suexec-caller=${APACHE_USER}			\
			--suexec-safepath='${APACHE_SUEXEC_PATH}'	\
			--suexec-docroot=${APACHE_SUEXEC_DOCROOT}
CONFIGURE_ARGS+=	--enable-suexec 				\
			${APACHE_SUEXEC_CONFIGURE_ARGS:M--suexec-*}
PLIST_SRC=		${PKGDIR}/PLIST.suexec
BUILD_DEFS+=		APACHE_SUEXEC_CONFIGURE_ARGS
.endif

# Note that there is NO static compile module hook here.  This is intentional.
# Under Apache 1.3, modules can be compiled to link dynamically to the server
# using the "apxs" program.  See apxs(8).
#
.if !defined(NOPIC)
CONFIGURE_ARGS+=	--enable-module=so	# requires dlopen()
_ENABLE_MOD=		--enable-shared
PLIST_SRC+=		${PKGDIR}/PLIST.shared
.else
_ENABLE_MOD=		--enable-module
.endif
PLIST_SRC+=		${PKGDIR}/PLIST

CONFIGURE_ARGS+=	${_ENABLE_MOD}=proxy
CONFIGURE_ARGS+=	${_ENABLE_MOD}=define	# from mod_ssl pkg.addon

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
CONFIGURE_ENV+=		INCLUDES="-I${BUILDLINK_PREFIX.db2}/include/db2"
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

MAKE_DIRS=		${PREFIX}/share/httpd
MAKE_DIRS+=		${PREFIX}/share/httpd/htdocs
OWN_DIRS+=		${PREFIX}/lib/httpd
OWN_DIRS+=		/var/httpd
OWN_DIRS+=		/var/log/httpd
OWN_DIRS_PERMS+=	/var/httpd/proxy ${APACHE_USER} ${APACHE_GROUP} 0755

PKG_GROUPS=		${APACHE_GROUP}
PKG_USERS=		${APACHE_USER}:${APACHE_GROUP}::Apache\\ user

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
	@${SED} ${FILES_SUBST_SED}					\
		${FILESDIR}/config.layout > ${WRKDIR}/config.layout

pre-install:
	${FIND} ${WRKSRC}/htdocs -name '*.orig' -print | ${XARGS} ${RM} -f

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

.include "../../devel/libmm/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
