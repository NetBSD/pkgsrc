# $NetBSD: Makefile,v 1.144 2013/12/01 10:18:02 ryoon Exp $

.include "Makefile.common"

PKGNAME=	apache-${APACHE_VERSION}
PKGREVISION=	1
CATEGORIES=	www

HOMEPAGE=	http://httpd.apache.org/
COMMENT=	Apache HTTP (Web) server, version 2
LICENSE=	apache-2.0

CONFLICTS=	apache-*ssl-[0-9]* apache6-[0-9]*

BUILD_DEFS+=	IPV6_READY
BUILD_DEFS+=	VARBASE

USE_TOOLS+=		pax perl perl:run pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-layout=NetBSD
CONFIGURE_ARGS+=	--with-port=80
CONFIGURE_ARGS+=	--enable-so
CONFIGURE_ENV+=		perlbin=${PERL5:Q}

# Apache Portable Runtime library configure options
CONFIGURE_ARGS+=	--with-apr=${BUILDLINK_PREFIX.apr}
CONFIGURE_ARGS+=	--with-apr-util=${BUILDLINK_PREFIX.apr}

.include "../../devel/apr0/buildlink3.mk"
BUILDLINK_API_DEPENDS.apr+=	apr>=0.9.12.2.0.58

# the following must be set before bsd.prefs.mk in order to make += work
# in mk.conf; however, it isn't expanded until referenced, so we can
# define DFLT_APACHE_MODULES later
#
APACHE_MODULES?=	${DFLT_APACHE_MODULES}

.include "../../mk/bsd.prefs.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"

# Set the "Multi-Processing Model" used by Apache to handle requests.
# Valid values are:
#	prefork		non-threaded, pre-forking web server
#	worker		hybrid multi-threaded multi-process web server
#
APACHE_MPM?=		prefork
CONFIGURE_ARGS+=	--with-mpm=${APACHE_MPM:Q}
BUILD_DEFS+=		APACHE_MPM
PLIST_VARS+=		mpm-prefork mpm-worker
PLIST.${APACHE_MPM}=	yes

CONFIGURE_ARGS+=	--disable-access
CONFIGURE_ARGS+=	--disable-auth
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
CONFIGURE_ARGS+=	--disable-imap
CONFIGURE_ARGS+=	--disable-actions
CONFIGURE_ARGS+=	--disable-userdir
CONFIGURE_ARGS+=	--disable-alias

DFLT_APACHE_MODULES=	all
DFLT_APACHE_MODULES+=	proxy proxy_connect proxy_ftp proxy_http
DFLT_APACHE_MODULES+=	ssl deflate
DFLT_APACHE_MODULES+=	access auth include log_config env mime setenvif
DFLT_APACHE_MODULES+=	status autoindex asis cgi negotiation dir imap
DFLT_APACHE_MODULES+=	actions userdir alias

# LDAP support
.if !empty(PKG_BUILD_OPTIONS.apr:Mldap)
DFLT_APACHE_MODULES+=	ldap auth_ldap
.endif

# APACHE_MODULES are the modules that are linked statically into the
# apache httpd executable.
#
CONFIGURE_ARGS+=	--enable-modules=${APACHE_MODULES:Q}
BUILD_DEFS+=		APACHE_MODULES

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
CONF_FILES=		${EGDIR}/httpd-std.conf ${PKG_SYSCONFDIR}/httpd.conf
CONF_FILES+=		${EGDIR}/ssl-std.conf ${PKG_SYSCONFDIR}/ssl.conf
CONF_FILES+=		${SBINDIR}/envvars-std ${SBINDIR}/envvars
CONF_FILES+=		${EGDIR}/magic ${PKG_SYSCONFDIR}/magic
CONF_FILES+=		${EGDIR}/mime.types ${PKG_SYSCONFDIR}/mime.types
RCD_SCRIPTS=		apache

REQD_DIRS=		${PREFIX}/share/httpd
REQD_DIRS+=		${PREFIX}/share/httpd/htdocs
OWN_DIRS=	${VARBASE}/log/httpd
OWN_DIRS+=		${VARBASE}/db/httpd
OWN_DIRS_PERMS+=	${VARBASE}/db/httpd/proxy ${APACHE_USER} ${APACHE_GROUP} 0755
FIX_PERMS=		apachectl apxs dbmmanage envvars-std mkcert
FIX_MAN_PERMS=		man1/htdbm.1 man1/htpasswd.1 man1/htdigest.1
FIX_MAN_PERMS+=		man1/dbmmanage.1 man8/httpd.8 man8/suexec.8
FIX_MAN_PERMS+=		man8/rotatelogs.8 man8/logresolve.8 man8/apxs.8
FIX_MAN_PERMS+=		man8/apachectl.8 man8/ab.8

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
SUBST_FILES.paths=	config.layout
SUBST_SED.paths=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_SED.paths+=	-e "s|@VARBASE@|${VARBASE}|g"
SUBST_SED.paths+=	-e "s|@SYSCONFDIR@|${PKG_SYSCONFDIR}|g"
SUBST_MESSAGE.paths=	Fixing paths.

SUBST_CLASSES+=		apr-lt
SUBST_STAGE.apr-lt=	post-configure
SUBST_FILES.apr-lt=	build/config_vars.mk
SUBST_SED.apr-lt=	-e 's|^\(LIBTOOL =\) [^ ]*|\1 $$(SHELL) $$(top_builddir)/build/libtool|g'
SUBST_MESSAGE.apr-lt=	Fixing libtool references.

SUBST_CLASSES+=		confs
SUBST_STAGE.confs=	post-configure
SUBST_MESSAGE.confs=	Fixing configuration files.
SUBST_FILES.confs=	docs/conf/highperformance-std.conf
SUBST_FILES.confs+=	docs/conf/httpd-std.conf
SUBST_FILES.confs+=	docs/conf/ssl-std.conf
SUBST_SED.confs=	-e "s|${EGDIR}|${PKG_SYSCONFDIR}|g"
SUBST_SED.confs+=	-e "s|${PREFIX}/htdocs|${PREFIX}/share/httpd/htdocs|g"
SUBST_SED.confs+=	-e "s|${PREFIX}/conf|${PKG_SYSCONFDIR}|g"
SUBST_SED.confs+=	-e "s|logs/|${VARBASE}/log/httpd/|g"
SUBST_SED.confs+=	-e 's|/var/log/httpd/foo\.log|logs/foo.log/|g'
SUBST_SED.confs+=	-e 's|^\(User[	 ]\).*|\1${APACHE_USER}|g'
SUBST_SED.confs+=	-e 's|^\(Group[	 ]\).*|\1${APACHE_GROUP}|g'

# abs_srcdir in config_vars.mk is used during install so needs to reference
# the work dir path, and by other packages such as ap2-fastcgi after install,
# so we fix after install to reference the installed path
SUBST_CLASSES+=		abs_srcdir
SUBST_STAGE.abs_srcdir=	post-install
SUBST_FILES.abs_srcdir=	${DESTDIR}${PREFIX}/share/httpd/build/config_vars.mk
SUBST_SED.abs_srcdir=	-e 's|^\(abs_srcdir =\) .*|\1 ${PREFIX}/share/httpd|'
SUBST_MESSAGE.abs_srcdir=	Fixing abs_srcdir

REPLACE_PERL=		docs/cgi-examples/printenv

.include "options.mk"

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

.for ap_mod in ${APACHE_MODULES}
.  if defined(AP_DEPENDS.${ap_mod}) && !empty(AP_DEPENDS.${ap_mod})
.    for ap_depend in ${AP_DEPENDS.${ap_mod}}
.      if exists(${ap_depend})
.        include "${ap_depend}"
.      else
DEPENDS+=		${ap_depend}
.      endif
.    endfor
.  endif
.  if defined(AP_CFG_ARGS.${ap_mod}) && !empty(AP_CFG_ARGS.${ap_mod})
CONFIGURE_ARGS+=	${AP_CFG_ARGS.${ap_mod}}
.  endif
.endfor

post-extract:
	${TOUCH} ${WRKSRC}/build/libtool

post-build:
	${SED} "s#@PKG_SYSCONFDIR@#${PKG_SYSCONFDIR}#g"			\
		< ${FILESDIR}/mkcert.sh > ${WRKDIR}/mkcert

INSTALLATION_DIRS+=	share/httpd/manual

pre-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV}				\
		${MAKE_PROGRAM} install-conf sysconfdir="${EGDIR}" \
		    DESTDIR=${DESTDIR}

post-install:
	${LN} -sf ../../../libexec/apr/libtool ${DESTDIR}${PREFIX}/share/httpd/build
	cd ${DESTDIR}${EGDIR} &&					\
	for file in							\
		highperformance-std.conf				\
		httpd-std.conf						\
		ssl-std.conf;						\
	do								\
		${AWK} '						\
			/^Listen[ 	]*80/	{			\
				printf "%s", "Listen 0.0.0.0:80\n";	\
				next;					\
			}						\
			/^Listen[ 	]*443/	{			\
				printf "%s", "Listen 0.0.0.0:443\n";	\
				next;					\
			}						\
			{ print; }					\
			' < "$${file}" >> $${file}.new;			\
		${MV} -f $${file}.new $${file};				\
	done

	cd ${WRKSRC}/docs/manual && pax -rw . ${DESTDIR}${PREFIX}/share/httpd/manual

	${INSTALL_SCRIPT} ${WRKDIR}/mkcert ${DESTDIR}${PREFIX}/sbin

	for file in ${FIX_PERMS}; do \
		${CHOWN} ${BINOWN}:${BINGRP} ${DESTDIR}${PREFIX}/sbin/$$file && \
		${CHMOD} ${BINMODE} ${DESTDIR}${PREFIX}/sbin/$$file; \
	done

	${CHOWN} -h -R ${BINOWN}:${BINGRP} ${DESTDIR}${PREFIX}/share/httpd
	${CHOWN} -h -R ${BINOWN}:${BINGRP} ${DESTDIR}${PREFIX}/include/httpd
	${CHOWN} -h -R ${BINOWN}:${BINGRP} ${DESTDIR}${PREFIX}/lib/httpd
	${CHOWN} ${BINOWN}:${BINGRP} ${DESTDIR}${PREFIX}/libexec/cgi-bin/test-cgi
	${CHOWN} ${BINOWN}:${BINGRP} ${DESTDIR}${PREFIX}/libexec/cgi-bin/printenv

	for file in ${FIX_MAN_PERMS}; do \
		${CHOWN} ${MANOWN}:${MANGRP} ${DESTDIR}${PREFIX}/${PKGMANDIR}/$$file; \
	done

	${INSTALL_SCRIPT} ${WRKSRC}/build/mkdir.sh ${DESTDIR}${PREFIX}/share/httpd/build

.include "../../mk/bsd.pkg.mk"
