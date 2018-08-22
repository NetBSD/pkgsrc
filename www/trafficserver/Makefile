# $NetBSD: Makefile,v 1.10 2018/08/22 09:47:59 wiz Exp $

DISTNAME=	trafficserver-7.1.2
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_APACHE:=trafficserver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://trafficserver.apache.org/
COMMENT=	Fast, scalable and extensible caching proxy server
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	bash:run gmake perl:run pkg-config

GNU_CONFIGURE=	yes

# For man pages
PYTHON_FOR_BUILD_ONLY=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37
BUILD_DEPENDS+=			${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

.include "../../mk/bsd.prefs.mk"

.include "options.mk"

BODY_FILES+=	access__denied access__proxy_auth_required			\
		access__ssl_forbidden cache__not_in_cache cache__read_error	\
		congestion__retryAfter connect__dns_failed			\
		connect__failed_connect connect__hangup default			\
		interception__no_host redirect__moved_permanently		\
		redirect__moved_temporarily request__cycle_detected		\
		request__invalid_content_length request__no_content_length	\
		request__no_host request__scheme_unsupported			\
		request__syntax_error response__bad_response			\
		response__bad_version timeout__activity	timeout__inactivity	\
		transcoding__unsupported urlrouting__no_mapping

CONFIG_FILES+=	cache cluster congestion hosting ip_allow log_hosts logging	\
		metrics parent plugin records remap socks splitdns		\
		ssl_multicert storage vaddrs volume

EGDIR=			share/examples/${PKGBASE}

PKG_SYSCONFSUBDIR=	${PKGBASE}
PKG_SYSCONFDIR_PERMS+=	${TS_USER} ${TS_GROUP} 0755
MAKE_DIRS_PERMS+=	${PKG_SYSCONFDIR}/body_factory/default			\
			${TS_USER} ${TS_GROUP} 0755
MAKE_DIRS_PERMS+=	${PKG_SYSCONFDIR}/snapshots				\
			${TS_USER} ${TS_GROUP} 0755
OWN_DIRS_PERMS+=	${TS_DIR} ${TS_USER} ${TS_GROUP} 0755
OWN_DIRS_PERMS+=	${TS_LOGDIR} ${TS_USER} ${TS_GROUP} 0755

.for file in ${BODY_FILES}
CONF_FILES_PERMS+=	${EGDIR}/body_factory/default/${file:S/__/\#/}		\
			${PKG_SYSCONFDIR}/body_factory/default/${file:S/__/\#/}	\
			${TS_USER} ${TS_GROUP} 0644
.endfor
.for file in ${CONFIG_FILES}
CONF_FILES_PERMS+=	${EGDIR}/${file}.config.default				\
			${PKG_SYSCONFDIR}/${file}.config 			\
			${TS_USER} ${TS_GROUP} 0644
.endfor

TS_USER?=		trafserv
TS_GROUP?=		trafserv
TS_DIR=			${VARBASE}/trafficserver
TS_LOGDIR=		${VARBASE}/log/trafficserver

PKG_GROUPS=		${TS_GROUP}
PKG_USERS=		${TS_USER}:${TS_GROUP}
PKG_GROUPS_VARS=	TS_GROUP
PKG_USERS_VARS=		TS_USER
PKG_GECOS.${TS_USER}=	TrafficServer user
PKG_HOME.${TS_USER}=	${TS_DIR}
PKG_SHELL.${TS_USER}=	${NOLOGIN}

PERL5_CONFIGURE=	no
PERL5_PACKLIST=		auto/Apache/TS/.packlist

CONFIGURE_ARGS+=	--enable-docs
CONFIGURE_ARGS+=	--disable-silent-rules
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-group=${TS_GROUP}
CONFIGURE_ARGS+=	--with-user=${TS_USER}

CONFIGURE_ENV.SunOS+=	ac_cv_func_epoll_ctl=no
CONFIGURE_ENV.SunOS+=	ac_cv_func_inotify_init=no
CONFIGURE_ENV+=		SPHINXBUILD=sphinx-build${PYVERSSUFFIX}

REPLACE_BASH+=		tools/tsxs.in
REPLACE_PERL+=		tools/tspush

INSTALL_MAKE_FLAGS+=	pkgsysconfdir=${PREFIX}/${EGDIR}
INSTALL_MAKE_FLAGS+=	${MAKE_PARAMS}

PKGCONFIG_OVERRIDE+=	tools/trafficserver.pc.in

SMF_SRCDIR=		${WRKSRC}/rc
SMF_MANIFEST=		trafficserver.xml

PLIST_VARS+=		inotify
.if ${OPSYS} == "Linux"
PLIST.inotify=		yes
.endif

TEST_TARGET=		check

.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
