# $NetBSD: Makefile,v 1.48 2004/10/02 16:38:38 reed Exp $

PKGNAME=		apache-${APACHE_VERSION}
PKGREVISION=		1
CATEGORIES=		www

HOMEPAGE=		http://httpd.apache.org/
COMMENT=		Apache HTTP (Web) server, version 2

CONFLICTS=		apache-*ssl-[0-9]* apache-[0-9]* apache6-[0-9]*

BUILD_DEFS+=		USE_INET6

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES

#USE_LIBTOOL=		YES
#LIBTOOL_OVERRIDE=	libtool

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-layout=NetBSD
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-port=80
CONFIGURE_ARGS+=	--with-mpm=prefork

# Apache Portable Runtime library configure options
CONFIGURE_ARGS+=	--with-apr=${LOCALBASE}
CONFIGURE_ARGS+=	--with-apr-util=${LOCALBASE}

.include "../../mk/bsd.prefs.mk"

DFLT_APACHE_MODULES=	all
DFLT_APACHE_MODULES+=	proxy proxy_connect proxy_ftp proxy_http
DFLT_APACHE_MODULES+=	ssl

# OpenLDAP support
.if !empty(APR_USE_OPENLDAP:M[Yy][Ee][Ss])
DFLT_APACHE_MODULES+=	ldap auth_ldap
.include "../../databases/openldap/buildlink3.mk"
.endif

APACHE_MODULES?=	${DFLT_APACHE_MODULES}
CONFIGURE_ARGS+=	--enable-modules="${APACHE_MODULES}"
CONFIGURE_ARGS+=	--enable-so
BUILD_DEFS+=		APACHE_MODULES

APACHE_USER?=	www
APACHE_GROUP?=	www

SUEXEC_COMMENT?=	"@comment "
.if defined(APACHE_SUEXEC) && ${APACHE_SUEXEC} == YES
APACHE_SUEXEC_DOCROOT?= ${PREFIX}/share/httpd/htdocs
APACHE_SUEXEC_PATH=     /bin:/usr/bin:${PREFIX}/bin:/usr/local/bin
APACHE_SUEXEC_CONFIGURE_ARGS+=						\
			--with-suexec-bin=${PREFIX}/sbin/suexec		\
			--with-suexec-caller=${APACHE_USER}		\
			--with-suexec-safepath='${APACHE_SUEXEC_PATH}'	\
			--with-suexec-docroot=${APACHE_SUEXEC_DOCROOT}	\
			--with-suexec-logfile=${VARBASE}/log/httpd/suexec.log
APACHE_MODULES+=	suexec
CONFIGURE_ARGS+=	${APACHE_SUEXEC_CONFIGURE_ARGS:M--with-suexec-*}
BUILD_DEFS+=		APACHE_SUEXEC APACHE_SUEXEC_CONFIGURE_ARGS
SUEXEC_COMMENT=		# empty

.endif

PKG_GROUPS=		${APACHE_GROUP}
PKG_USERS=		${APACHE_USER}:${APACHE_GROUP}::Apache\\ user

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

MAKE_DIRS=		${PREFIX}/share/httpd
MAKE_DIRS+=		${PREFIX}/share/httpd/htdocs
OWN_DIRS= 		${VARBASE}/log/httpd
OWN_DIRS+=		${VARBASE}/db/httpd
OWN_DIRS_PERMS+=	${VARBASE}/db/httpd/proxy ${APACHE_USER} ${APACHE_GROUP} 0755
FIX_PERMS=		apachectl apxs dbmmanage envvars-std

SUBST_CLASSES=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	config.layout	
SUBST_SED.paths=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_MESSAGE.paths=	"Fixing paths."

SUBST_CLASSES+=		confs
SUBST_STAGE.confs=	post-install
SUBST_FILES.confs=	${EGDIR}/highperformance-std.conf \
			${EGDIR}/httpd-std.conf \
			${EGDIR}/ssl-std.conf
SUBST_SED.confs=	-e "s|${EGDIR}|${PKG_SYSCONFDIR}|g" \
			-e "s|${PREFIX}/htdocs|${PREFIX}/share/httpd/htdocs|g" \
			-e "s|${PREFIX}/conf|${PKG_SYSCONFDIR}|g" \
			-e "s|logs/|${VARBASE}/log/httpd/|g" \
			-e "s|/var/log/httpd/foo\.log|logs/foo.log/|g" \
			-e "s|^\(User[	 ]\).*|\1${APACHE_USER}|g" \
			-e "s|^\(Group[	 ]\).*|\1${APACHE_GROUP}|g"
SUBST_MESSAGE.confs=	"Fixing configuration files."

# Add dependencies for the modules that will be built.  For each module
# ap_mod listed in ${APACHE_MODULES}, _AP_DEPENDS.ap_mod is a whitespace
# separated list of dependencies or buildlink3.mk files needed to build
# ap_mod, and _AP_CFG_ARGS.ap_mod is a whitespace separated list of
# configure script options for ap_mod.
#
_AP_DEPENDS.ssl=	../../security/openssl/buildlink3.mk
_AP_DEPENDS.deflate=	../../devel/zlib/buildlink3.mk

_AP_CFG_ARGS.ssl=	--with-ssl=${BUILDLINK_PREFIX.openssl}
_AP_CFG_ARGS.deflate=	--with-z=${BUILDLINK_PREFIX.zlib}

.for _ap_mod in ${APACHE_MODULES}
.  if defined(_AP_DEPENDS.${_ap_mod}) && !empty(_AP_DEPENDS.${_ap_mod})
.    for _ap_depend in ${_AP_DEPENDS.${_ap_mod}}
.      if exists(${_ap_depend})
.        include "${_ap_depend}"
.      else
DEPENDS+=		${_ap_depend}
.      endif
.    endfor
.  endif
.  if defined(_AP_CFG_ARGS.${_ap_mod}) && !empty(_AP_CFG_ARGS.${_ap_mod})
CONFIGURE_ARGS+=	${_AP_CFG_ARGS.${_ap_mod}}
.  endif
.endfor

pre-install:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV}				\
		${MAKE_PROGRAM} install-conf sysconfdir="${EGDIR}"
 
post-install:
	@${LN} -sf ${LOCALBASE}/libexec/apr/libtool ${PREFIX}/share/httpd/build
	@cd ${EGDIR};							\
	for file in							\
		highperformance-std.conf				\
		httpd-std.conf						\
		ssl-std.conf;						\
	do								\
		${CAT} $${file}	| ${AWK} '				\
			/^Listen[ 	]*80/	{			\
				print;					\
				printf "%s", "Listen 0.0.0.0:80\n";	\
				next;					\
			}						\
			/^Listen[ 	]*443/	{			\
				print;					\
				printf "%s", "Listen 0.0.0.0:443\n";	\
				next;					\
			}						\
			{ print; }					\
			' >> $${file}.new;				\
		${MV} -f $${file}.new $${file};				\
	done

	@${INSTALL_DATA_DIR} ${PREFIX}/share/httpd/manual
	@cd ${WRKSRC}/docs/manual && ${PAX} -rw . ${PREFIX}/share/httpd/manual

	for file in ${FIX_PERMS}; do \
		${CHOWN} ${BINOWN}:${BINGRP} ${PREFIX}/sbin/$$file && \
		${CHMOD} ${BINMODE} ${PREFIX}/sbin/$$file; \
	done

.include "Makefile.common"

.include "../../devel/apr/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
