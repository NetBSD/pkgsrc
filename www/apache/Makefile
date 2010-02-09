# $NetBSD: Makefile,v 1.199 2010/02/09 07:22:06 dholland Exp $
#
# This pkg does not compile in mod_ssl, only the `mod_ssl EAPI' (a set of
# code hooks that allow mod_ssl to be compiled separately later, if desired).

DISTNAME=		apache_1.3.42
PKGNAME=		${DISTNAME:S/_/-/}
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_APACHE:=httpd/} \
			${MASTER_SITE_APACHE:=httpd/old/}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} ${NETBSD_LOGO} ${MODSSL_DIST}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://httpd.apache.org/
COMMENT=		Apache HTTP (Web) server

PKG_DESTDIR_SUPPORT=	user-destdir

NETBSD_LOGO=		sitedrivenby.gif
SITES.${NETBSD_LOGO}=	http://www.NetBSD.org/images/logos/

MODSSL_VERSION=		2.8.31
MODSSL_DISTNAME=	mod_ssl-${MODSSL_VERSION}-1.3.41
MODSSL_DIST=		${MODSSL_DISTNAME}.tar.gz
MODSSL_SRC=		${WRKDIR}/${MODSSL_DISTNAME}
SITES.${MODSSL_DIST}=	http://www.modssl.org/source/ \
			ftp://ftp.pca.dfn.de/pub/tools/net/mod_ssl/source/ \
			ftp://ftp.funet.fi/pub/crypt/cryptography/libs/modssl/source/

CONFLICTS=		apache-*ssl-[0-9]* apache6-[0-9]*

EXTRACT_ONLY=		${DISTFILES:N*.gif}
# Actually, apache is only written in C, but we need this so that
# a dlopen()ed apache module that's written in C++ will have static
# objects constructed properly.
USE_LANGUAGES=		c c++
HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-layout="${WRKSRC}/config.layout:pkgsrc"
CONFIGURE_ARGS+=	--enable-module=most				\
			--enable-module=auth_db				\
			--disable-module=auth_dbm
CONFIGURE_ARGS+=	--enable-rule=EAPI				\
			--disable-module=ssl
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--without-confadjust
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}
CONFIGURE_ARGS+=	--with-port=80
CONFIGURE_ENV+=		OPTIM=${APACHE_CUSTOM_CFLAGS:Q}
CONFIGURE_ENV+=		EAPI_MM="${BUILDLINK_PREFIX.libmm}"
CONFIGURE_ENV+=		BINOWN=${BINOWN:Q} BINGRP=${BINGRP:Q}
INSTALL_MAKE_FLAGS+=	root=${DESTDIR:Q}

.include "../../mk/bsd.prefs.mk"

.if empty(STRIPFLAG)
CONFIGURE_ARGS+=	--without-execstrip
.endif

PKG_SYSCONFSUBDIR?=	httpd
USE_TOOLS+=		perl

APACHE_USER?=		www
APACHE_GROUP?=		www
PKG_USERS_VARS+=	APACHE_USER
PKG_GROUPS_VARS+=	APACHE_GROUP

CONFIGURE_ARGS+=	--server-uid=${APACHE_USER:Q}
CONFIGURE_ARGS+=	--server-gid=${APACHE_GROUP:Q}

PKG_OPTIONS_VAR=	PKG_OPTIONS.apache
PKG_SUPPORTED_OPTIONS=	perf-tuning suexec

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msuexec)
APACHE_SUEXEC_DOCROOT?=	${PREFIX}/share/httpd/htdocs
APACHE_SUEXEC_PATH=	/bin:/usr/bin:${PREFIX}/bin:/usr/local/bin
APACHE_SUEXEC_CONFIGURE_ARGS+=						\
			--suexec-caller=${APACHE_USER}			\
			--suexec-safepath=${APACHE_SUEXEC_PATH:Q}	\
			--suexec-docroot=${APACHE_SUEXEC_DOCROOT}
CONFIGURE_ARGS+=	--enable-suexec 				\
			${APACHE_SUEXEC_CONFIGURE_ARGS:M--suexec-*}
PLIST_SRC=		${PKGDIR}/PLIST.suexec
BUILD_DEFS+=	 	APACHE_SUEXEC_DOCROOT
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

.if !empty(PKG_OPTIONS:Mperf-tuning)
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
MAKE_ENV+=		LINK_LIBGCC_LDFLAGS=${LINK_LIBGCC_LDFLAGS:Q}
#
# If we are using gcc3, we need to link against libgcc_s, too.  This
# ensures modules can resolve symbols they require from gcc.
#
.    if !empty(CC_VERSION:Mgcc-3*)
LINK_LIBGCC_LDFLAGS+=	-lgcc_s
.    endif
.  endif
.endif

BUILD_DEFS+=		APACHE_CUSTOM_CFLAGS APACHE_USER APACHE_GROUP

EGDIR=		${PREFIX}/share/examples/httpd

CONF_FILES=	${EGDIR}/httpd.conf.default ${PKG_SYSCONFDIR}/httpd.conf
CONF_FILES+=	${EGDIR}/magic.default ${PKG_SYSCONFDIR}/magic
CONF_FILES+=	${EGDIR}/mime.types.default ${PKG_SYSCONFDIR}/mime.types
RCD_SCRIPTS=	apache

REQD_DIRS=		${PREFIX}/share/httpd
REQD_DIRS+=		${PREFIX}/share/httpd/htdocs
REQD_DIRS+=		${PREFIX}/lib/httpd
OWN_DIRS+=		${VARBASE}/httpd
OWN_DIRS+=		${VARBASE}/log/httpd
OWN_DIRS_PERMS+=	${VARBASE}/httpd/proxy ${APACHE_USER} ${APACHE_GROUP} 0755

#
# Fix paths in the apache manpages.
#
SUBST_CLASSES+=		man
SUBST_STAGE.man=	post-patch
SUBST_FILES.man=	src/support/*.1 src/support/*.8
SUBST_SED.man=		-e 's,/usr/local/apache/conf,${PKG_SYSCONFDIR},'
SUBST_SED.man+=		-e 's,/usr/local/etc/apache,${PKG_SYSCONFDIR},'
SUBST_SED.man+=		-e 's,/path/to/apache/etc,${PKG_SYSCONFDIR},'
SUBST_SED.man+=		-e 's,/usr/local/apache/logs,${VARBASE}/log/httpd,'
SUBST_SED.man+=		-e 's,/usr/local/apache,${PREFIX}/share/httpd/htdocs,'
SUBST_SED.man+=		-e 's,/usr/web,${PREFIX}/share/httpd/htdocs,'

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	config.layout
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,@VARBASE@,${VARBASE},g'
SUBST_STAGE.paths=	post-patch

.include "../../mk/bdb.buildlink3.mk"
SUBST_CLASSES+=         db
SUBST_STAGE.db=         post-patch
SUBST_FILES.db=         src/modules/standard/mod_auth_db.module
SUBST_SED.db+=          -e 's,@DB_LIB@,${BDB_LIBS},g'
SUBST_SED.db+=          -e 's,@DB_VERSION@,${BDB_TYPE},g'
.if defined(BDB_BASE) && !empty(BDB_BASE)
SUBST_SED.db+=          -e 's,@DB_CFLAGS@,-I${BDB_BASE}/include,g'
.else
SUBST_SED.db+=          -e 's,@DB_CFLAGS@,,g'
.endif

REPLACE_PERL+=			cgi-bin/printenv
CHECK_INTERPRETER_SKIP+=	lib/httpd/httpd.exp

PKG_GROUPS=		${APACHE_GROUP}
PKG_USERS=		${APACHE_USER}:${APACHE_GROUP}

MAKE_ENV+=		CHMOD=${CHMOD:Q} CHOWN=${CHOWN:Q} XARGS=${XARGS:Q}
MAKE_ENV+=		FIND=${FIND:Q} CHGRP=${CHGRP:Q}

.include "../../devel/libmm/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"

post-extract:
	${CP} ${FILESDIR}/ap_include_extern.h ${WRKSRC}/src/include
	${CP} ${MODSSL_SRC}/pkg.addon/*.c ${WRKSRC}/src/modules/extra
	${CP} ${MODSSL_SRC}/pkg.addon/*.html ${WRKSRC}/htdocs/manual/mod
	${CP} ${MODSSL_SRC}/pkg.eapi/*.c ${WRKSRC}/src/ap
	${CP} ${MODSSL_SRC}/pkg.eapi/*.h ${WRKSRC}/src/include
	${CP} ${FILESDIR}/config.layout ${WRKSRC}

pre-patch:
	cd ${WRKSRC} && ${CAT}						\
		${MODSSL_SRC}/pkg.addon/addon.patch			\
		${MODSSL_SRC}/pkg.eapi/eapi.patch			\
		${MODSSL_SRC}/pkg.sslcfg/sslcfg.patch			\
		${MODSSL_SRC}/pkg.sslmod/sslmod.patch			\
		${MODSSL_SRC}/pkg.sslsup/sslsup.patch			\
		| ${PATCH} ${PATCH_ARGS}
	cd ${WRKSRC} && ${TAIL} -n +160					\
		${MODSSL_SRC}/pkg.ssldoc/ssldoc.patch			\
		| ${PATCH} ${PATCH_ARGS}
	${FIND} ${WRKSRC} -name '*.orig' -print | ${XARGS} ${RM} -f

post-patch:
	cd ${WRKSRC}/src/support;					\
	${SED}	-e "s|@INSTALL@|"`${TYPE} ${INSTALL} | ${AWK} '{ print $$NF }'`" -c -o ${LIBOWN} -g ${LIBGRP}|" \
		apxs.pl > apxs.pl.sed;					\
	${MV} apxs.pl.sed apxs.pl

pre-install:
	${FIND} ${WRKSRC}/htdocs -name '*.orig' -print | ${XARGS} ${RM} -f

post-install:
.if !defined(NOPIC)
	cd ${DESTDIR}${PREFIX}/lib/httpd; ${MV} libproxy.so mod_proxy.so
.endif
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/httpd
	for file in httpd.conf magic mime.types; do			\
		${INSTALL_DATA} ${DESTDIR}${PKG_SYSCONFDIR}/$${file}.default	\
			${DESTDIR}${PREFIX}/share/examples/httpd;	\
		${RM} -f ${DESTDIR}${PKG_SYSCONFDIR}/$${file}.default;	\
	done
	${INSTALL_DATA} ${DISTDIR}/sitedrivenby.gif ${DESTDIR}${PREFIX}/share/httpd/htdocs
	${CHMOD} ${NONBINMODE} ${DESTDIR}${PREFIX}/libexec/cgi-bin/printenv \
	  ${DESTDIR}${PREFIX}/libexec/cgi-bin/test-cgi

.include "../../mk/bsd.pkg.mk"
