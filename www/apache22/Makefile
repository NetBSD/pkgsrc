# $NetBSD: Makefile,v 1.95 2013/12/03 21:18:36 bsiegert Exp $

DISTNAME=	httpd-2.2.25
PKGNAME=	${DISTNAME:S/httpd/apache/}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_APACHE:=httpd/} \
		http://archive.apache.org/dist/httpd/ \
		http://archive.eu.apache.org/dist/httpd/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://httpd.apache.org/
COMMENT=	Apache HTTP (Web) server, version 2.2
LICENSE=	apache-2.0

BUILD_DEFS+=	IPV6_READY
BUILD_DEFS+=	VARBASE

USE_TOOLS+=		pax perl perl:run pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-layout=NetBSD
CONFIGURE_ARGS+=	--with-port=80
CONFIGURE_ARGS+=	--enable-so
CONFIGURE_ENV+=		perlbin=${PERL5:Q}
CONFIGURE_ENV+=		ac_cv_path_RSYNC=/nonexistent
CONFIGURE_ARGS+=	CFLAGS=${APACHE_CUSTOM_CFLAGS:M*:Q}

BUILD_DEFS+=		APACHE_CUSTOM_CFLAGS

# Apache Portable Runtime library configure options
CONFIGURE_ARGS+=	--with-apr=${BUILDLINK_PREFIX.apr}
CONFIGURE_ARGS+=	--with-apr-util=${BUILDLINK_PREFIX.apr-util}

CHECK_INTERPRETER_SKIP+=	lib/httpd/httpd.exp
CHECK_PORTABILITY_SKIP+=	srclib/pcre/* \
				srclib/apr-util/* \
				srclib/apr/*

# the following must be set before bsd.prefs.mk in order to make += work
# in mk.conf; however, it isn't expanded until referenced, so we can
# define DFLT_APACHE_MODULES later
#
APACHE_MODULES?=	${DFLT_APACHE_MODULES}

.include "../../mk/bsd.prefs.mk"
.include "../../devel/apr/buildlink3.mk"
.include "../../devel/apr-util/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

CONFIGURE_ARGS+=	--disable-include
CONFIGURE_ARGS+=	--disable-log-config
CONFIGURE_ARGS+=	--disable-env
CONFIGURE_ARGS+=	--disable-mime
CONFIGURE_ARGS+=	--disable-setenvif
CONFIGURE_ARGS+=	--disable-status
CONFIGURE_ARGS+=	--disable-autoindex
CONFIGURE_ARGS+=	--disable-asis
CONFIGURE_ARGS+=	--disable-cgi
CONFIGURE_ARGS+=	--disable-negotiation
CONFIGURE_ARGS+=	--disable-dir
CONFIGURE_ARGS+=	--disable-actions
CONFIGURE_ARGS+=	--disable-userdir
CONFIGURE_ARGS+=	--disable-alias

DFLT_APACHE_MODULES=	all
DFLT_APACHE_MODULES+=	proxy proxy_connect proxy_ftp proxy_http
DFLT_APACHE_MODULES+=	ssl deflate access auth authn_alias
DFLT_APACHE_MODULES+=	include log_config env mime setenvif
DFLT_APACHE_MODULES+=	status autoindex asis cgi negotiation dir imap
DFLT_APACHE_MODULES+=	actions userdir alias isapi file_cache
DFLT_APACHE_MODULES+=	cache disk_cache mem_cache bucketeer echo
DFLT_APACHE_MODULES+=	example case_filter case_filter_in
DFLT_APACHE_MODULES+=	charset_lite
DFLT_APACHE_MODULES+=	cgid dav_lock proxy_ajp proxy_balancer

PLIST_SRC+=		${PKGDIR}/PLIST

.include "options.mk"

# LDAP support
PLIST_VARS+=		ldap
.if !empty(PKG_BUILD_OPTIONS.apr-util:Mldap)
DFLT_APACHE_MODULES+=	ldap authnz_ldap
.  if !empty(PKG_OPTIONS:Mapache-shared-modules)
PLIST.ldap=		yes
.  endif
.endif

APACHE_USER?=		www
APACHE_GROUP?=		www
PKG_GROUPS=		${APACHE_GROUP}
PKG_USERS=		${APACHE_USER}:${APACHE_GROUP}
PKG_GROUPS_VARS+=	APACHE_GROUP
PKG_USERS_VARS+=	APACHE_USER

PKG_SYSCONFVAR=		apache
PKG_SYSCONFSUBDIR?=	httpd
EGDIR=			${PREFIX}/share/examples/httpd
SBINDIR=		${PREFIX}/sbin
CONF_FILES+=		${EGDIR}/httpd.conf ${PKG_SYSCONFDIR}/httpd.conf
.for f in autoindex dav default info languages manual mpm \
	  multilang-errordoc ssl userdir vhosts
CONF_FILES+=		${EGDIR}/extra/httpd-${f}.conf \
				${PKG_SYSCONFDIR}/httpd-${f}.conf
.endfor
CONF_FILES+=		${EGDIR}/magic ${PKG_SYSCONFDIR}/magic
CONF_FILES+=		${EGDIR}/mime.types ${PKG_SYSCONFDIR}/mime.types
RCD_SCRIPTS=		apache

REQD_DIRS=		${PREFIX}/share/httpd
REQD_DIRS+=		${PREFIX}/share/httpd/htdocs
OWN_DIRS=		${VARBASE}/log/httpd
OWN_DIRS+=		${VARBASE}/db/httpd
OWN_DIRS_PERMS+=	${VARBASE}/db/httpd/proxy ${APACHE_USER} ${APACHE_GROUP} 0755
FIX_PERMS=		apachectl apxs dbmmanage envvars-std mkcert
FIX_MAN_PERMS=		man1/htdbm.1 man1/htpasswd.1 man1/htdigest.1
FIX_MAN_PERMS+=		man1/dbmmanage.1 man8/httpd.8 man8/suexec.8
FIX_MAN_PERMS+=		man8/rotatelogs.8 man1/logresolve.1 man1/apxs.1
FIX_MAN_PERMS+=		man8/apachectl.8 man1/ab.1 man1/httxt2dbm.1

# Fix paths in the apache manpages.
SUBST_CLASSES+=		man
SUBST_STAGE.man=	post-patch
SUBST_FILES.man=	docs/man/*.1 docs/man/*.8
SUBST_SED.man=		-e 's,/usr/local/etc/apache,${PKG_SYSCONFDIR},'
SUBST_SED.man+=		-e 's,/path/to/apache/etc,${PKG_SYSCONFDIR},'
SUBST_SED.man+=		-e 's,/usr/local/apache2,${PREFIX}/share/httpd/htdocs,'
SUBST_SED.man+=		-e 's,/usr/web,${PREFIX}/share/httpd/htdocs,'

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	config.layout Makefile.in support/apxs.in
SUBST_SED.paths=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_SED.paths+=	-e "s|@VARBASE@|${VARBASE}|g"
SUBST_SED.paths+=	-e "s|@SYSCONFDIR@|${PKG_SYSCONFDIR}|g"
SUBST_SED.paths+=	-e "s|@PAX@|${PAX}|g"
SUBST_SED.paths+=	-e "s|@LOCALBASE@|${LOCALBASE}|g"
SUBST_MESSAGE.paths=	Fixing paths.

SUBST_CLASSES+=		apr-lt
SUBST_STAGE.apr-lt=	post-configure
SUBST_FILES.apr-lt=	build/config_vars.mk
SUBST_SED.apr-lt=	-e 's|^\(LIBTOOL =\) [^ ]*|\1 $$(SHELL) $$(top_builddir)/build/libtool|g'
SUBST_MESSAGE.apr-lt=	Fixing libtool references.

SUBST_CLASSES+=		confs
SUBST_STAGE.confs=	post-configure
SUBST_MESSAGE.confs=	Fixing configuration files.
SUBST_FILES.confs=	docs/conf/httpd.conf
SUBST_FILES.confs+=	docs/conf/extra/httpd-ssl.conf
SUBST_SED.confs=	-e "s|${EGDIR}|${PKG_SYSCONFDIR}|g"
SUBST_SED.confs+=	-e "s|${PREFIX}/htdocs|${PREFIX}/share/httpd/htdocs|g"
SUBST_SED.confs+=	-e "s|${PREFIX}/conf|${PKG_SYSCONFDIR}|g"
SUBST_SED.confs+=	-e "s|logs/|${VARBASE}/log/httpd/|g"
SUBST_SED.confs+=	-e 's|/var/log/httpd/foo\.log|logs/foo.log/|g'
SUBST_SED.confs+=	-e 's|^\(User[	 ]\).*|\1${APACHE_USER}|g'
SUBST_SED.confs+=	-e 's|^\(Group[	 ]\).*|\1${APACHE_GROUP}|g'
SUBST_SED.confs+=	-e 's|^Listen \(.*\)|Listen 0.0.0.0:\1|g'

# abs_srcdir in config_vars.mk is used during install so needs to reference
# the work dir path, and by other packages such as ap2-fastcgi after install,
# so we fix after install to reference the installed path
SUBST_CLASSES+=		abs_srcdir
SUBST_STAGE.abs_srcdir=	post-install
SUBST_FILES.abs_srcdir=	${DESTDIR}${PREFIX}/share/httpd/build/config_vars.mk
SUBST_SED.abs_srcdir=	-e 's|^\(abs_srcdir =\) .*|\1 ${PREFIX}/share/httpd|'
SUBST_MESSAGE.abs_srcdir=	Fixing abs_srcdir

REPLACE_PERL=		docs/cgi-examples/printenv

# Add dependencies for the modules that will be built.  For each module
# ap_mod listed in ${APACHE_MODULES}, _AP_DEPENDS.ap_mod is a whitespace
# separated list of dependencies or buildlink3.mk files needed to build
# ap_mod, and _AP_CFG_ARGS.ap_mod is a whitespace separated list of
# configure script options for ap_mod.
#
AP_DEPENDS.ssl=	../../security/openssl/buildlink3.mk
AP_DEPENDS.deflate=	../../devel/zlib/buildlink3.mk

AP_CFG_ARGS.ssl=	--with-ssl=${BUILDLINK_PREFIX.openssl}
AP_CFG_ARGS.deflate=	--with-z=${BUILDLINK_PREFIX.zlib}

#.if ${APACHE_MODULES} == "all-shared"
.if !empty(PKG_OPTIONS:Mapache-shared-modules)
.  include "${AP_DEPENDS.ssl}"
.  include "${AP_DEPENDS.deflate}"
CONFIGURE_ARGS+=	${AP_CFG_ARGS.ssl} ${AP_CFG_ARGS.deflate}
.else
.  for ap_mod in ${APACHE_MODULES}
.    if defined(AP_DEPENDS.${ap_mod}) && !empty(AP_DEPENDS.${ap_mod})
.      for ap_depend in ${AP_DEPENDS.${ap_mod}}
.        if exists(${ap_depend})
.          include "${ap_depend}"
.        else
DEPENDS+=		${ap_depend}
.        endif
.      endfor
.    endif
.    if defined(AP_CFG_ARGS.${ap_mod}) && !empty(AP_CFG_ARGS.${ap_mod})
CONFIGURE_ARGS+=	${AP_CFG_ARGS.${ap_mod}}
.    endif
.  endfor
.endif

post-extract:
	${TOUCH} ${WRKSRC}/build/libtool
	${ECHO} "" >> ${WRKSRC}/docs/conf/extra/httpd-languages.conf.in

post-build:
	${SED} "s#@PKG_SYSCONFDIR@#${PKG_SYSCONFDIR}#g"			\
		< ${FILESDIR}/mkcert.sh > ${WRKDIR}/mkcert

INSTALL_TARGET=		install-conf install
INSTALL_MAKE_FLAGS+=	sysconfdir="${EGDIR}"

post-install:
	${LN} -sf ${LOCALBASE}/libexec/apr/libtool ${DESTDIR}${PREFIX}/share/httpd/build
	${LN} -sf ${SBINDIR}/envvars-std ${DESTDIR}${SBINDIR}/envvars

	${INSTALL_SCRIPT} ${WRKDIR}/mkcert ${DESTDIR}${PREFIX}/sbin

	for file in ${FIX_PERMS}; do \
		${CHOWN} ${BINOWN}:${BINGRP} ${DESTDIR}${PREFIX}/sbin/$$file && \
		${CHMOD} ${BINMODE} ${DESTDIR}${PREFIX}/sbin/$$file; \
	done

	${CHOWN} -R ${BINOWN}:${BINGRP} ${DESTDIR}${PREFIX}/share/httpd
	${CHOWN} -R ${BINOWN}:${BINGRP} ${DESTDIR}${PREFIX}/include/httpd
	${CHOWN} -R ${BINOWN}:${BINGRP} ${DESTDIR}${PREFIX}/lib/httpd
	${CHOWN} ${BINOWN}:${BINGRP} ${DESTDIR}${PREFIX}/libexec/cgi-bin/test-cgi
	${CHOWN} ${BINOWN}:${BINGRP} ${DESTDIR}${PREFIX}/libexec/cgi-bin/printenv

	for file in ${FIX_MAN_PERMS}; do \
		${CHOWN} ${MANOWN}:${MANGRP} ${DESTDIR}${PREFIX}/${PKGMANDIR}/$$file; \
	done

	${CHMOD} -x ${DESTDIR}${PREFIX}/sbin/envvars-std
	${TEST} ! -f ${DESTDIR}${PREFIX}/sbin/suexec || ${CHMOD} -w ${DESTDIR}${PREFIX}/sbin/suexec

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
