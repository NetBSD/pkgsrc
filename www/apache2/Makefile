# $NetBSD: Makefile,v 1.2 2002/03/05 23:56:22 jlam Exp $

DISTNAME=		httpd-2.0.32-beta
PKGNAME=		apache-2.0.32
WRKSRC=			${WRKDIR}/httpd-2.0.32
CATEGORIES=		www
MASTER_SITES=		http://httpd.apache.org/dist/httpd/ \
			http://httpd.apache.org/dist/httpd/old/ \
			http://www.netbsd.org/images/logos/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://httpd.apache.org/
COMMENT=		HTTP (Web) server, version 2 (BETA)

CONFLICTS=		apache-*modssl-[0-9]* apache-[0-9]* apache6-[0-9]*
CONFLICTS+=		ap-*-[0-9]*	# Apache-1.x DSOs

BUILD_DEFS+=		USE_INET6

USE_BUILDLINK_ONLY=	YES
REPLACE_BUILDLINK=	config_vars.mk
REPLACE_BUILDLINK_SED=	-e "s|${BUILDLINK_DIR}|${LOCALBASE}|g"

USE_GMAKE=		YES
PLIST_SRC=		# empty

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/srclib/apr/libtool

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-layout=NetBSD
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-port=80
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_DIR}

# Apache Portable Runtime library configure options
CONFIGURE_ARGS+=	--with-mpm=prefork

# Apache Portable Runtime Utility library configure options
CONFIGURE_ARGS+=	--with-dbm=sdbm
CONFIGURE_ARGS+=	--with-expat=${BUILDLINK_DIR}

.include "../../mk/bsd.prefs.mk"

APACHE_MODULES=		all
APACHE_MODULES+=	proxy proxy-connect proxy-ftp proxy-http
APACHE_MODULES+=	ssl

.if defined(NOPIC) || (defined(MKPIC) && (${MKPIC} == "no"))
CONFIGURE_ARGS+=	--enable-modules="${APACHE_MODULES}"
CONFIGURE_ARGS+=	--disable-so
.else
CONFIGURE_ARGS+=	--enable-mods-shared="${APACHE_MODULES}"
CONFIGURE_ARGS+=	--enable-so
PLIST_SRC+=		${.CURDIR}/PLIST.shared
.endif

SUEXEC_COMMENT?=	"@comment "
.if defined(APACHE_SUEXEC) && ${APACHE_SUEXEC} == YES
APACHE_SUEXEC_USER?=	www
APACHE_SUEXEC_GROUP?=	nogroup
APACHE_SUEXEC_DOCROOT?= ${PREFIX}/share/apache/htdocs
APACHE_SUEXEC_PATH=     /bin:/usr/bin:${PREFIX}/bin:/usr/local/bin
APACHE_SUEXEC_CONFIGURE_ARGS+=						\
			--with-suexec-bin=${PREFIX}/sbin/suexec		\
			--with-suexec-caller=${APACHE_SUEXEC_USER}	\
			--with-suexec-safepath='${APACHE_SUEXEC_PATH}'	\
			--with-suexec-docroot=${APACHE_SUEXEC_DOCROOT}
APACHE_MODULES+=	suexec
CONFIGURE_ARGS+=	${APACHE_SUEXEC_CONFIGURE_ARGS:M--with-suexec-*}
BUILD_DEFS+=		APACHE_SUEXEC APACHE_SUEXEC_CONFIGURE_ARGS
SUEXEC_COMMENT=		# empty

PKG_GROUPS=		${APACHE_SUEXEC_GROUP}
PKG_USERS=		${APACHE_SUEXEC_USER}:${APACHE_SUEXEC_GROUP}::Apache\\ suEXEC\\ user
.endif

PLIST_SRC+=		${.CURDIR}/PLIST
PLIST_SUBST+=		SUEXEC_COMMENT=${SUEXEC_COMMENT}

PKG_SYSCONFVAR=		apache
PKG_SYSCONFSUBDIR?=	httpd
EGDIR=			${PREFIX}/share/examples/httpd
SBINDIR=		${PREFIX}/sbin
CONF_FILES=		${EGDIR}/httpd-std.conf ${PKG_SYSCONFDIR}/httpd.conf
CONF_FILES+=		${EGDIR}/ssl-std.conf ${PKG_SYSCONFDIR}/ssl.conf
SUPPORT_FILES=		${SBINDIR}/envvars-std ${SBINDIR}/envvars
SUPPORT_FILES+=		${EGDIR}/magic ${PKG_SYSCONFDIR}/magic
SUPPORT_FILES+=		${EGDIR}/mime.types ${PKG_SYSCONFDIR}/mime.types
RCD_SCRIPTS=		apache

# Fix problems with the Apache configure process.  It's still in flux in
# moving over to a GNU autoconf framework, and is missing some of the
# flexibility of the way it used to be done via APACI.
#
# We override preprocessor definitions that are used in Apache sources.
# The values we use are derived from the NetBSD layout of the
# config.layout file.
#
CONFIGURE_ENV+=		NOTEST_CPPFLAGS="${NOTEST_CPPFLAGS}"

# Override values in server/mpm/<MPM>/mpm_default.h.
NOTEST_CPPFLAGS=							\
	-DDEFAULT_ERRORLOG=\\\"\$$(logfiledir)/error_log\\\"		\
	-DDEFAULT_LOCKFILE=\\\"\$$(runtimedir)/accept.lock\\\"		\
	-DDEFAULT_PIDLOG=\\\"\$$(runtimedir)/httpd.pid\\\"		\
	-DDEFAULT_SCOREBOARD=\\\"\$$(runtimedir)/apache_runtime_status\\\"

# Used in server/config.c and server/main.c to locate default config file.
NOTEST_CPPFLAGS+=							\
	-DSERVER_CONFIG_FILE=\\\"\$$(sysconfdir)/httpd.conf\\\"

# Override value in include/httpd.h and used in modules/http/mod_mime.c
# to locate default MIME types file.
#
NOTEST_CPPFLAGS+=							\
	-DAP_TYPES_CONFIG_FILE=\\\"\$$(sysconfdir)/mime.types\\\"

post-extract:
	cd ${WRKSRC}/support;						\
	${MV} apxs.in apxs.pl.in;					\
	${MV} apachectl.in apachectl.sh.in;				\
	${MV} dbmmanage.in dbmmanage.pl.in

post-configure:
	cd ${WRKSRC}; for file in config_vars.mk; do			\
		${SED} -e "s|^\(sysconfdir\)[ 	]*=.*|\1 = ${PKG_SYSCONFDIR}|g" \
			$${file} > $${file}.new;			\
		${MV} -f $${file}.new $${file};				\
	done

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/apache.sh > ${WRKDIR}/apache.sh

post-install:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV}				\
		${MAKE_PROGRAM} install-conf sysconfdir="${EGDIR}"
	cd ${EGDIR};							\
	for file in							\
		highperformance-std.conf				\
		httpd-std.conf						\
		ssl-std.conf;						\
	do								\
		${SED}	-e "s|${EGDIR}|${PKG_SYSCONFDIR}|g"		\
			$${file} >> $${file}.new;			\
		${MV} -f $${file}.new $${file};				\
	done
	${INSTALL_SCRIPT} ${WRKDIR}/apache.sh ${PREFIX}/etc/rc.d/apache

.include "../../lang/perl5/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../textproc/expat/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
