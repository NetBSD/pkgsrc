# $NetBSD: Makefile,v 1.143 2004/04/25 06:21:11 snj Exp $
#
# This pkg does not compile in mod_ssl, only the `mod_ssl EAPI' (a set of
# code hooks that allow mod_ssl to be compiled separately later, if desired).

DISTNAME=		apache_${APACHE_VERSION}
PKGNAME=		apache-${APACHE_VERSION}
PKGREVISION=		2
APACHE_VERSION=		1.3.29
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_APACHE:=httpd/} \
			${MASTER_SITE_APACHE:=httpd/old/}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} ${NETBSD_LOGO} ${MODSSL_DIST}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://httpd.apache.org/
COMMENT=		Apache HTTP (Web) server

NETBSD_LOGO=		sitedrivenby.gif
SITES_${NETBSD_LOGO}=	http://www.NetBSD.org/images/logos/

MODSSL_VERSION=		2.8.16
MODSSL_DISTNAME=	mod_ssl-${MODSSL_VERSION}-1.3.29
MODSSL_DIST=		${MODSSL_DISTNAME}.tar.gz
MODSSL_SRC=		${WRKDIR}/${MODSSL_DISTNAME}
SITES_${MODSSL_DIST}=	http://www.modssl.org/source/ \
			ftp://ftp.pca.dfn.de/pub/tools/net/mod_ssl/source/ \
			ftp://ftp.funet.fi/pub/crypt/cryptography/libs/modssl/source/

CONFLICTS=		apache-*ssl-[0-9]* apache6-[0-9]*

EXTRACT_ONLY=		${DISTFILES:N*.gif}
USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
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

.if defined(APACHE_PERF_TUNING) && ${APACHE_PERF_TUNING} == "YES"
APACHE_CUSTOM_CFLAGS+=	-DBUFFERED_LOGS
APACHE_CUSTOM_CFLAGS+=	${COMPILER_PERFTUNE_FLAGS}
LDFLAGS+=		${COMPILER_PERFTUNE_FLAGS}
.endif

# Explicitly turn on large file support
APACHE_CUSTOM_CFLAGS+=	-D_LARGEFILE_SOURCE
APACHE_CUSTOM_CFLAGS+=	-D_FILE_OFFSET_BITS=64

.include "../../mk/compiler.mk"

# On NetBSD ELF platforms, we need to link libgcc.a whole-archive so that
# certain symbols from the C++ implementation (__get_eh_context, etc.)
# referenced by DSOs written in C++ will resolve correctly.
#
.if ${OPSYS} == "NetBSD"
.  if ${OBJECT_FMT} == "ELF"
LINK_LIBGCC_LDFLAGS=	${LINK_ALL_LIBGCC_HACK}
MAKE_ENV+=		LINK_LIBGCC_LDFLAGS="${LINK_LIBGCC_LDFLAGS}"
# if we are using gcc3, we need to link against libgcc_s, too. This
# ensures modules can resolve symbols they require from gcc.
.    if !empty(CC_VERSION:Mgcc-3*)
USE_GCC_SHLIB=		YES # defined
LINK_LIBGCC_LDFLAGS+=	-lgcc_s
.    endif
.  endif
.endif

# Use operating system's db1 functions (where available)
USE_DB185=		# defined

.include "../../databases/db/buildlink3.mk"
BUILDLINK_DEPENDS.db=	db>=2.7.7

.if defined(BUILDLINK_PREFIX.db_DEFAULT)
CONFIGURE_ENV+=		INCLUDES="${BUILDLINK_CPPFLAGS.db}"

# on Solaris, we also need libdbm
.  if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=		LIBS="-ldbm -ldb2"
LDFLAGS+=		-Wl,${RPATH_FLAG}/usr/ucblib -L/usr/ucblib
.  else
CONFIGURE_ENV+=		LIBS="-ldb2"
.  endif
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

MAKE_ENV+=		CHMOD="${CHMOD}" CHOWN="${CHOWN}" XARGS="${XARGS}"
MAKE_ENV+=		FIND="${FIND}" CHGRP="${CHGRP}"

post-extract:
	@${CP} ${FILESDIR}/ap_include_extern.h ${WRKSRC}/src/include
	@${CP} ${MODSSL_SRC}/pkg.addon/*.c ${WRKSRC}/src/modules/extra
	@${CP} ${MODSSL_SRC}/pkg.addon/*.html ${WRKSRC}/htdocs/manual/mod
	@${CP} ${MODSSL_SRC}/pkg.eapi/*.c ${WRKSRC}/src/ap
	@${CP} ${MODSSL_SRC}/pkg.eapi/*.h ${WRKSRC}/src/include

pre-patch:
	@cd ${WRKSRC} && ${CAT}						\
		${MODSSL_SRC}/pkg.addon/addon.patch			\
		${MODSSL_SRC}/pkg.eapi/eapi.patch			\
		${MODSSL_SRC}/pkg.sslcfg/sslcfg.patch			\
		${MODSSL_SRC}/pkg.sslmod/sslmod.patch			\
		${MODSSL_SRC}/pkg.sslsup/sslsup.patch			\
		| ${PATCH} ${PATCH_ARGS}
	@cd ${WRKSRC} && ${TAIL} +160					\
		${MODSSL_SRC}/pkg.ssldoc/ssldoc.patch			\
		| ${PATCH} ${PATCH_ARGS}
	@${FIND} ${WRKSRC} -name '*.orig' -print | ${XARGS} ${RM} -f

post-patch:
	@cd ${WRKSRC}/src/support;					\
	${SED}	-e "s|@INSTALL@|"`${TYPE} ${INSTALL} | ${AWK} '{ print $$NF }'`" -c -o ${LIBOWN} -g ${LIBGRP}|" \
		apxs.pl > apxs.pl.sed;					\
	${MV} apxs.pl.sed apxs.pl

pre-configure:
	@${SED} ${FILES_SUBST_SED}					\
		${FILESDIR}/config.layout > ${WRKDIR}/config.layout

pre-install:
	@${FIND} ${WRKSRC}/htdocs -name '*.orig' -print | ${XARGS} ${RM} -f

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
	${CHMOD} ${NONBINMODE} ${PREFIX}/libexec/cgi-bin/printenv \
	  ${PREFIX}/libexec/cgi-bin/test-cgi

.include "../../devel/libmm/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
