# $NetBSD: Makefile,v 1.81 2003/09/17 19:41:19 grant Exp $
#
# This package does not compile in mod_ssl support hooks, as it conflicts
# with IPv6-enable patch.
#
# IPv6-enable patch conflicts with third-party modules anyway, due to
# sanity fixes in apache module API (for example, avoid u_long for IPv4 addrs)

DISTNAME=		apache_${APACHE_VERSION}
PKGNAME=		apache6-${APACHE_VERSION}
<<<<<<< Makefile
#PKGREVISION=		3
APACHE_VERSION=		1.3.28
=======
APACHE_VERSION=		1.3.28
>>>>>>> 1.79
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_APACHE:=httpd/} \
			${MASTER_SITE_APACHE:=httpd/old/}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} ${NETBSD_LOGO}

PATCH_SITES+=		http://www.tendra.org/~asmodai/ipv6/
PATCHFILES+=		apache-1.3.28-v6-20030912.diff.gz

NETBSD_LOGO=		sitedrivenby.gif
SITES_${NETBSD_LOGO}=	

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://httpd.apache.org/
COMMENT=		Apache HTTP (Web) server with IPv6 support

CONFLICTS=		apache-[0-9]* apache-*ssl-[0-9]* apache6-[0-9]*

EXTRACT_ONLY=		${DISTFILES:N*.gif:N*.diff.gz}
USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-layout="${WRKDIR}/config.layout:pkgsrc"
CONFIGURE_ARGS+=	--enable-module=most \
			--enable-module=auth_db \
			--enable-module=so \
			--disable-module=auth_dbm \
			--enable-rule=INET6
# proxy module is broken with the IPv6 patch
CONFIGURE_ARGS+=	--disable-module=proxy
CONFIGURE_ARGS+=	--without-confadjust
CONFIGURE_ARGS+=	--with-perl=${PERL5}
CONFIGURE_ARGS+=	--with-port=80
CONFIGURE_ENV+=		OPTIM="${APACHE_CUSTOM_CFLAGS}"
CONFIGURE_ENV+=		EAPI_MM="${BUILDLINK_PREFIX.libmm}"

BUILD_DEFS+=		USE_INET6

.include "../../mk/bsd.prefs.mk"

.if !defined(USE_INET6) || ${USE_INET6} != YES
PKG_FAIL_REASON=	"IPv6 only build"
.endif

.if empty(STRIPFLAG)
CONFIGURE_ARGS+=	--without-execstrip
.endif

PKG_SYSCONFSUBDIR?=	httpd

APACHE_USER?=		www
APACHE_GROUP?=		www
BUILD_DEFS+=		APACHE_USER
BUILD_DEFS+=		APACHE_GROUP

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

PLIST_SRC+=		${PKGDIR}/PLIST

.if defined(NOPIC)
PLIST_SUBST+=		SHLIBS="@comment "
.else
PLIST_SUBST+=		SHLIBS=""
.endif

APACHE_CUSTOM_CFLAGS?=	# empty

.if defined(APACHE_PERF_TUNING) && ${APACHE_PERF_TUNING} == YES
APACHE_CUSTOM_CFLAGS+=	-DBUFFERED_LOGS
APACHE_CUSTOM_CFLAGS+=	-O6 -fomit-frame-pointer -fexpensive-optimizations
.endif

# Explicitly turn on large file support
APACHE_CUSTOM_CFLAGS+=	-D_LARGEFILE_SOURCE
APACHE_CUSTOM_CFLAGS+=	-D_FILE_OFFSET_BITS=64

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
.    if defined(USE_GCC3)
USE_GCC_SHLIB=		# defined
LINK_LIBGCC_LDFLAGS+=	-lgcc_s
.    endif
.  endif
.endif

# Use operating system's db1 functions (where available)
USE_DB185=		# defined

.include "../../databases/db/buildlink2.mk"
BUILDLINK_DEPENDS.db=	db>=2.7.7

.if defined(BUILDLINK_PREFIX.db_DEFAULT)
CONFIGURE_ENV+=		INCLUDES="-I${BUILDLINK_PREFIX.db}/include/db2"

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

PKG_GROUPS=		${APACHE_GROUP}
PKG_USERS=		${APACHE_USER}:${APACHE_GROUP}::Apache\\ user

EGDIR=		${PREFIX}/share/examples/httpd

CONF_FILES=	${EGDIR}/httpd.conf.default ${PKG_SYSCONFDIR}/httpd.conf
SUPPORT_FILES=	${EGDIR}/magic.default ${PKG_SYSCONFDIR}/magic
SUPPORT_FILES+=	${EGDIR}/mime.types.default ${PKG_SYSCONFDIR}/mime.types
RCD_SCRIPTS=	apache

OWN_DIRS+=		${PREFIX}/lib/httpd
OWN_DIRS+=		/var/httpd
OWN_DIRS+=		/var/log/httpd

pre-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -print | ${XARGS} ${RM} -f

post-patch:
	@cd ${WRKSRC}/src/support;					\
	${SED}	-e "s|@INSTALL@|"`${TYPE} ${INSTALL} | ${AWK} '{ print $$NF }'`" -c -o ${LIBOWN} -g ${LIBGRP}|" \
		apxs.pl > apxs.pl.sed;					\
	${MV} apxs.pl.sed apxs.pl
	@cp ${WRKSRC}/conf/httpd.conf-dist ${WRKSRC}/conf/httpd.conf-dist-
	@${SED}	-e "s|#Listen ::|Listen ::|"				\
		-e "s|#Listen 0.0.0.0|Listen 0.0.0.0|"			\
		${WRKSRC}/conf/httpd.conf-dist-				\
		> ${WRKSRC}/conf/httpd.conf-dist

pre-configure:
	@${SED} ${FILES_SUBST_SED}					\
		${FILESDIR}/config.layout > ${WRKDIR}/config.layout

pre-install:
	@${FIND} ${WRKSRC}/htdocs -name '*.orig' -print | ${XARGS} ${RM} -f

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/httpd
	for file in httpd.conf magic mime.types; do			\
		${INSTALL_DATA} ${PKG_SYSCONFDIR}/$${file}.default	\
			${PREFIX}/share/examples/httpd;			\
		${RM} -f ${PKG_SYSCONFDIR}/$${file}.default;		\
	done
	${INSTALL_DATA} ${DISTDIR}/sitedrivenby.gif ${PREFIX}/share/httpd/htdocs
	${CHMOD} ${NONBINMODE} ${PREFIX}/libexec/cgi-bin/printenv \
	  ${PREFIX}/libexec/cgi-bin/test-cgi

.include "../../devel/libmm/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
