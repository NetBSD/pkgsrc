# $NetBSD: Makefile,v 1.112 2022/06/28 11:37:02 wiz Exp $
#
# When updating this package, make sure that no strings like
# "PR 12345" are in the commit message. Upstream likes
# to reference their own PRs this way, but this ends up
# in NetBSD GNATS.

DISTNAME=	httpd-2.4.54
PKGNAME=	${DISTNAME:S/httpd/apache/}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_APACHE:=httpd/}
MASTER_SITES+=	https://archive.apache.org/dist/httpd/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://httpd.apache.org/
COMMENT=	Apache HTTP (Web) server, version 2.4
LICENSE=	apache-2.0

BUILD_DEFS+=	IPV6_READY
BUILD_DEFS+=	VARBASE

USE_LIBTOOL=		yes
USE_TOOLS+=		pax perl pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-layout=NetBSD
CONFIGURE_ARGS+=	--enable-mods-shared=all
CONFIGURE_ARGS+=	--enable-so
CONFIGURE_ARGS+=	--with-apr=${BUILDLINK_PREFIX.apr}
CONFIGURE_ARGS+=	--with-apr-util=${BUILDLINK_PREFIX.apr-util}
CONFIGURE_ARGS+=	--with-port=80
CONFIGURE_ENV+=		perlbin=${PERL5:Q}
CONFIGURE_ENV+=		ac_cv_path_RSYNC=/nonexistent

.include "../../mk/compiler.mk"

CFLAGS.SunOS+=	-D__EXTENSIONS__
.if !empty(CC_VERSION:Mgcc-[5-9]*) || !empty(CC_VERSION:Mgcc-1[0-9].*) || !empty(PKGSRC_COMPILER:Mclang)
CFLAGS.SunOS+=	-D_XOPEN_SOURCE=600
.else
CFLAGS.SunOS+=	-D_XOPEN_SOURCE -D_XOPEN_SOURCE_EXTENDED=1
.endif

BUILDLINK_API_DEPENDS.apr+=	apr>=1.5.0
.include "../../devel/apr/buildlink3.mk"
BUILDLINK_API_DEPENDS.apr-util+=	apr-util>=1.5.3
.include "../../devel/apr-util/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

CONFIGURE_ARGS+=	--enable-proxy-fdpass

DFLT_APACHE_MODULES+=	all
APACHE_MODULES?=	${DFLT_APACHE_MODULES}

.include "options.mk"

# LDAP support
PLIST_VARS+=		ldap
.if ${PKG_BUILD_OPTIONS.apr-util:Mldap}
DFLT_APACHE_MODULES+=	ldap authnz_ldap
PLIST.ldap=		yes
.endif

PLIST_VARS+=		ssl
.if ${PKG_BUILD_OPTIONS.apr-util:Mssl}
PLIST.ssl=		yes
.endif

APACHE_USER?=		www
APACHE_GROUP?=		www
PKG_GROUPS=		${APACHE_GROUP}
PKG_USERS=		${APACHE_USER}:${APACHE_GROUP}
PKG_GROUPS_VARS=	APACHE_GROUP
PKG_USERS_VARS=		APACHE_USER

PKG_SYSCONFVAR=		apache
PKG_SYSCONFSUBDIR=	httpd
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
FIX_PERMS_SBIN=		apachectl envvars-std
FIX_PERMS_BIN=		apxs dbmmanage mkcert
FIX_MAN_PERMS=		man1/htdbm.1 man1/htpasswd.1 man1/htdigest.1
FIX_MAN_PERMS+=		man1/dbmmanage.1 man8/httpd.8 man8/suexec.8
FIX_MAN_PERMS+=		man8/rotatelogs.8 man1/logresolve.1 man1/apxs.1
FIX_MAN_PERMS+=		man8/apachectl.8 man1/ab.1 man1/httxt2dbm.1

# Fix paths in the apache manpages.
SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fixing paths in man pages.
SUBST_FILES.man=	docs/man/apxs.1 docs/man/htdbm.1 \
			docs/man/htpasswd.1 docs/man/httpd.8
SUBST_SED.man=		-e 's,/usr/local/etc/apache,${PKG_SYSCONFDIR},'
SUBST_SED.man+=		-e 's,/path/to/apache/etc,${PKG_SYSCONFDIR},'
SUBST_SED.man+=		-e 's,/usr/local/apache2,${PREFIX}/share/httpd/htdocs,'
SUBST_SED.man+=		-e 's,/usr/web,${PREFIX}/share/httpd/htdocs,'

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing paths.
SUBST_FILES.paths=	config.layout Makefile.in support/apxs.in
SUBST_VARS.paths=	PREFIX
SUBST_VARS.paths+=	VARBASE
SUBST_SED.paths+=	-e "s|@SYSCONFDIR@|${PKG_SYSCONFDIR}|g"
SUBST_VARS.paths+=	PAX PREFIX

SUBST_CLASSES+=		apr-lt
SUBST_STAGE.apr-lt=	post-configure
SUBST_MESSAGE.apr-lt=	Fixing libtool references.
SUBST_FILES.apr-lt=	build/config_vars.mk
SUBST_SED.apr-lt=	-e 's|^\(LIBTOOL =\) [^ ]*|\1 $$(SHELL) $$(top_builddir)/build/libtool|g'

SUBST_CLASSES+=		confs
SUBST_STAGE.confs=	post-configure
SUBST_MESSAGE.confs=	Fixing configuration files.
SUBST_FILES.confs=	docs/conf/httpd.conf
SUBST_FILES.confs+=	docs/conf/extra/httpd-ssl.conf
SUBST_SED.confs=	-e "s|${EGDIR}|${PKG_SYSCONFDIR}|g"
SUBST_SED.confs+=	-e "s|${PREFIX}/htdocs|${PREFIX}/share/httpd/htdocs|g"
SUBST_SED.confs+=	-e "s|${PREFIX}/conf|${PKG_SYSCONFDIR}|g"
SUBST_SED.confs+=	-e 's|^\(User[	 ]\).*|\1${APACHE_USER}|g'
SUBST_SED.confs+=	-e 's|^\(Group[	 ]\).*|\1${APACHE_GROUP}|g'
SUBST_SED.confs+=	-e 's|^Listen \(.*\)|Listen 0.0.0.0:\1|g'

# abs_srcdir in config_vars.mk is used during install so needs to reference
# the work dir path, and by other packages such as ap2-fastcgi after install,
# so we fix after install to reference the installed path
SUBST_CLASSES+=			abs_srcdir
SUBST_STAGE.abs_srcdir=		post-install
SUBST_MESSAGE.abs_srcdir=	Fixing abs_srcdir
SUBST_FILES.abs_srcdir=		${DESTDIR}${PREFIX}/share/httpd/build/config_vars.mk
SUBST_SED.abs_srcdir=		-e 's|^\(abs_srcdir =\) .*|\1 ${PREFIX}/share/httpd|'

#REPLACE_PERL=		docs/cgi-examples/printenv

.include "../../devel/zlib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-z=${BUILDLINK_PREFIX.zlib}

post-extract:
	${TOUCH} ${WRKSRC}/build/libtool
	${ECHO} "" >> ${WRKSRC}/docs/conf/extra/httpd-languages.conf.in

post-build:
	${SED} "s#@PKG_SYSCONFDIR@#${PKG_SYSCONFDIR}#g"			\
		< ${FILESDIR}/mkcert.sh > ${WRKDIR}/mkcert

INSTALL_TARGET=		install-conf install
INSTALL_MAKE_FLAGS+=	sysconfdir="${EGDIR}"

post-install:
	${LN} -sf ${PREFIX}/libexec/apr/libtool ${DESTDIR}${PREFIX}/share/httpd/build
	${LN} -sf ${SBINDIR}/envvars-std ${DESTDIR}${SBINDIR}/envvars

	${INSTALL_SCRIPT} ${WRKDIR}/mkcert ${DESTDIR}${PREFIX}/bin

.for file in ${FIX_PERMS_SBIN}
	${CHOWN} ${BINOWN}:${BINGRP} ${DESTDIR}${PREFIX}/sbin/${file}
	${CHMOD} ${BINMODE} ${DESTDIR}${PREFIX}/sbin/${file}
.endfor

.for file in ${FIX_PERMS_BIN}
	${CHOWN} ${BINOWN}:${BINGRP} ${DESTDIR}${PREFIX}/bin/${file}
	${CHMOD} ${BINMODE} ${DESTDIR}${PREFIX}/bin/${file}
.endfor

	${CHOWN} -RP ${BINOWN}:${BINGRP} ${DESTDIR}${PREFIX}/share/httpd
	${CHOWN} -RP ${BINOWN}:${BINGRP} ${DESTDIR}${PREFIX}/include/httpd
	${CHOWN} -RP ${BINOWN}:${BINGRP} ${DESTDIR}${PREFIX}/lib/httpd
	${CHOWN} ${BINOWN}:${BINGRP} ${DESTDIR}${PREFIX}/libexec/cgi-bin/test-cgi
	${CHOWN} ${BINOWN}:${BINGRP} ${DESTDIR}${PREFIX}/libexec/cgi-bin/printenv

.for file in ${FIX_MAN_PERMS}
	${CHOWN} ${MANOWN}:${MANGRP} ${DESTDIR}${PREFIX}/${PKGMANDIR}/${file}
.endfor

	${CHMOD} a-x ${DESTDIR}${PREFIX}/sbin/envvars-std
.if exists(${DESTDIR}${PREFIX}/sbin/suexec)
	${CHMOD} a-w ${DESTDIR}${PREFIX}/sbin/suexec
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
