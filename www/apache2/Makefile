# $NetBSD: Makefile,v 1.9 2002/06/18 23:58:07 itojun Exp $

DISTNAME=		httpd-2.0.39
PKGNAME=		apache-2.0.39
CATEGORIES=		www
MASTER_SITES=		http://httpd.apache.org/dist/httpd/ \
			http://httpd.apache.org/dist/httpd/old/ \
			ftp://ftp.fu-berlin.de/unix/network/www/apache/httpd/ \
			http://www.netbsd.org/images/logos/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://httpd.apache.org/
COMMENT=		HTTP (Web) server, version 2

CONFLICTS=		apache-*modssl-[0-9]* apache-[0-9]* apache6-[0-9]*
CONFLICTS+=		ap-*-[0-9]*	# Apache-1.x DSOs

BUILD_DEFS+=		USE_INET6

USE_BUILDLINK_ONLY=	YES
REPLACE_BUILDLINK=	config_vars.mk
REPLACE_BUILDLINK_SED=	-e "s|${BUILDLINK_DIR}|${LOCALBASE}|g"

USE_GMAKE=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/shlibtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/srclib/apr/libtool

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-layout=NetBSD
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-port=80

# Apache Portable Runtime library configure options
CONFIGURE_ARGS+=	--with-mpm=prefork --with-devrandom=/dev/urandom

# Apache Portable Runtime Utility library configure options
CONFIGURE_ARGS+=	--with-dbm=sdbm
CONFIGURE_ARGS+=	--with-expat=${BUILDLINK_DIR}

.include "../../mk/bsd.prefs.mk"

DFLT_APACHE_MODULES=	all
DFLT_APACHE_MODULES+=	proxy proxy_connect proxy_ftp proxy_http
DFLT_APACHE_MODULES+=	ssl
APACHE_MODULES?=	${DFLT_APACHE_MODULES}
CONFIGURE_ARGS+=	--enable-modules="${APACHE_MODULES}"
CONFIGURE_ARGS+=	--enable-so
BUILD_DEFS+=		APACHE_MODULES

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
OWN_DIRS= 		/var/log/httpd
OWN_DIRS+=		/var/db/httpd
.if defined(APACHE_SUEXEC) && ${APACHE_SUEXEC} == YES
OWN_DIRS_PERMS+=	/var/db/httpd/proxy ${APACHE_SUEXEC_USER} ${APACHE_SUEXEC_GROUP} 0755
.else
OWN_DIRS_PERMS+=	/var/db/httpd/proxy nobody nobody 0755
.endif

# Add dependencies for the modules that will be built.  For each module
# ap_mod listed in ${APACHE_MODULES}, _AP_DEPENDS.ap_mod is a whitespace
# separated list of dependencies or buildlink.mk files needed to build
# ap_mod, and _AP_CFG_ARGS.ap_mod is a whitespace separated list of
# configure script options for ap_mod.
#
_AP_DEPENDS.ssl=	../../security/openssl/buildlink.mk
_AP_DEPENDS.deflate=	../../devel/zlib/buildlink.mk

_AP_CFG_ARGS.ssl=	--with-ssl=${BUILDLINK_DIR}
_AP_CFG_ARGS.deflate=	--with-z=${BUILDLINK_DIR}

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

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/apache.sh > ${WRKDIR}/apache.sh

AP_CONF_FILE_SED=	-e "s|${EGDIR}|${PKG_SYSCONFDIR}|g"
AP_CONF_FILE_SED+=	-e "s|${PREFIX}/htdocs|${PREFIX}/share/httpd/htdocs|g"
AP_CONF_FILE_SED+=	-e "s|${PREFIX}/conf|${PKG_SYSCONFDIR}|g"
AP_CONF_FILE_SED+=	-e "s|logs/|/var/log/httpd/|g"
AP_CONF_FILE_SED+=	-e "s|/var/log/httpd/foo\.log|logs/foo.log/|g"
.if defined(APACHE_SUEXEC) && ${APACHE_SUEXEC} == YES
AP_CONF_FILE_SED+=	-e "s|^\(User[	 ]\).*|\1${APACHE_SUEXEC_USER}|g"
AP_CONF_FILE_SED+=	-e "s|^\(Group[	 ]\).*|\1${APACHE_SUEXEC_GROUP}|g"
.endif

post-install:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV}				\
		${MAKE_PROGRAM} install-conf sysconfdir="${EGDIR}"
	@cd ${EGDIR};							\
	for file in							\
		highperformance-std.conf				\
		httpd-std.conf						\
		ssl-std.conf;						\
	do								\
		${CAT} $${file}						\
		| ${SED} ${AP_CONF_FILE_SED}				\
		| ${AWK} '						\
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
	${INSTALL_SCRIPT} ${WRKDIR}/apache.sh ${PREFIX}/etc/rc.d/apache

.include "../../lang/perl5/buildlink.mk"
.include "../../textproc/expat/buildlink.mk"

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
