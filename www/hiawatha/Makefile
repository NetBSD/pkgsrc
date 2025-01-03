# $NetBSD: Makefile,v 1.44 2025/01/03 16:35:32 hauke Exp $

PKGNAME=	hiawatha-${PKGVER}
DISTNAME=	hiawatha-v${PKGVER}
PKGVER=		11.6
PKGREVISION=	7
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITLAB:=hsleisink/hiawatha/-/archive/v${PKGVER}/}
EXTRACT_SUFX=	.tar.gz

DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	https://hiawatha.leisink.net/
COMMENT=	Advanced and secure webserver
LICENSE=	gnu-gpl-v2

HIAWATHA_CGIDIR=	libexec/ssi-cgi
HIAWATHA_DATADIR=	${VARBASE}/db/hiawatha
HIAWATHA_LOGDIR=	${VARBASE}/log/hiawatha
HIAWATHA_PIDDIR=	${VARBASE}/run
HIAWATHA_WEBROOT=	${VARBASE}/hiawatha

BUILD_DEFS+=		VARBASE

LDFLAGS.SunOS+=		-lsocket -lnsl

# Config file processing
CMAKE_BUILD_DIR=	.

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_BINDIR=${PREFIX}/${HIAWATHA_CGIDIR}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_LOCALSTATEDIR=${VARBASE}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_MANDIR=${PREFIX}/${PKGMANDIR}
CMAKE_CONFIGURE_ARGS+=	-DWORK_DIR=${VARBASE}/db/${PKGBASE}
CMAKE_CONFIGURE_ARGS+=	-DLOG_DIR=${HIAWATHA_LOGDIR}
CMAKE_CONFIGURE_ARGS+=	-DPID_DIR=${HIAWATHA_PIDDIR}
CMAKE_CONFIGURE_ARGS+=	-DWEBROOT_DIR=${HIAWATHA_WEBROOT}
CMAKE_CONFIGURE_ARGS+=	-DWORK_DIR=${HIAWATHA_DATADIR}
CMAKE_CONFIGURE_ARGS+=	-DCONFIG_DIR=${PKG_SYSCONFDIR}

.include "options.mk"

HIAWATHA_USER?=		hiawatha
HIAWATHA_GROUP?=	hiawatha

PKG_USERS_VARS+=	HIAWATHA_USER
PKG_GROUPS_VARS+=	HIAWATHA_GROUP
PKG_GROUPS=		${HIAWATHA_GROUP}
PKG_USERS=		${HIAWATHA_USER}:${HIAWATHA_GROUP}

PKG_GECOS.${HIAWATHA_USER}=	HIAWATHA web server user
PKG_HOME.${HIAWATHA_USER}=	${HIAWATHA_DATADIR}
PKG_SHELL.${HIAWATHA_USER}=	${NOLOGIN}

PKG_SYSCONFSUBDIR=	hiawatha

RCD_SCRIPTS=		hiawatha

EGDIR=			share/examples/hiawatha
CONFIG_FILES=		hiawatha.conf mimetype.conf cgi-wrapper.conf

INSTALLATION_DIRS+=	sbin ${PKGMANDIR}/man8
INSTALLATION_DIRS+=	${HIAWATHA_CGIDIR}
INSTALLATION_DIRS+=	share/examples/hiawatha/conf
INSTALLATION_DIRS+=	share/examples/hiawatha/html

OWN_DIRS=		${HIAWATHA_LOGDIR} ${HIAWATHA_WEBROOT}
OWN_DIRS_PERMS+=	${HIAWATHA_DATADIR} ${HIAWATHA_USER} \
				${HIAWATHA_GROUP} 0750

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Fixing PREFIX path.
SUBST_FILES.path=	man/hiawatha.1.in man/cgi-wrapper.1.in
SUBST_FILES.path+=	config/cgi-wrapper.conf config/hiawatha.conf.in
SUBST_SED.path=		-e 's,/usr,${PREFIX},g'

SUBST_CLASSES+=		uid
SUBST_STAGE.uid=	pre-configure
SUBST_MESSAGE.uid=	Configure Hiawatha user and group
SUBST_FILES.uid=	config/hiawatha.conf.in
SUBST_VARS.uid=		HIAWATHA_USER HIAWATHA_GROUP

SUBST_CLASSES=+		url
SUBST_STAGE.url=	pre-configure
SUBST_MESSAGE.url=	Updating upstream web url
SUBST_FILES.url=	config/index.xslt
SUBST_FILES.url+=	extra/index.html
SUBST_FILES.url+=	man/cgi-wrapper.1.in
SUBST_FILES.url+=	man/hiawatha.1.in
SUBST_FILES.url+=	man/lefh.1
SUBST_FILES.url+=	man/newroot.1
SUBST_FILES.url+=	man/ssi-cgi.1
SUBST_FILES.url+=	man/wigwam.1
SUBST_SED.url=		-e 's/www.hiawatha-webserver.org/hiawatha.leisink.net/g'
SUBST_SED.url+=		-e 's/@hiawatha-webserver.org/@leisink.net/g'

.if !empty(HIAWATHA_REPLACE_MBEDTLS:Myes)
SUBST_CLASSES+=		mbopt
SUBST_STAGE.mbopt=	pre-configure
SUBST_MESSAGE.mbopt=	Setting options for updated mbedtls library
SUBST_FILES.mbopt=	mbedtls/include/mbedtls/mbedtls_config.h
# Enable threading support
SUBST_SED.mbopt=	-E -e 's,^//(\#define MBEDTLS_THREADING_PTHREAD),\1,g'
SUBST_SED.mbopt+=	-e 's,^//(\#define MBEDTLS_THREADING_C),\1,g'
SUBST_SED.mbopt+=	-e 's,^//(\#define MBEDTLS_SSL_PROTO_TLS1_3),\1,g'
SUBST_SED.mbopt+=	-e 's,^//(\#define MBEDTLS_SSL_TLS1_3_COMPATIBILITY_MODE),\1,g'
# Disable secp192r1 and secp192k1
SUBST_SED.mbopt+=	-e 's,(^\#define MBEDTLS_ECP_DP_SECP192R1_ENABLED),//\1,g'
SUBST_SED.mbopt+=	-e 's,(^\#define MBEDTLS_ECP_DP_SECP192K1_ENABLED),//\1,g'
.endif

# mbedtls-private
PRINT_PLIST_AWK+=	{ gsub(/^lib\/hiawatha\/libmbed.+$$/, "$${PLIST.mbedtls-private}&"); }
# urltoolkit
PRINT_PLIST_AWK+=	{ gsub(/^${EGDIR:S/\//\\\//g}\/toolkit.conf$$/, "$${PLIST.urltoolkit}&"); }
# xslt
PRINT_PLIST_AWK+=	{ gsub(/^${EGDIR:S/\//\\\//g}\/error.xslt$$/, "$${PLIST.xslt}&"); }
PRINT_PLIST_AWK+=	{ gsub(/^${EGDIR:S/\//\\\//g}\/index.xslt$$/, "$${PLIST.xslt}&"); }
# letsencrypt
PRINT_PLIST_AWK+=	{ gsub(/^lib\/hiawatha\/letsencrypt\/.+$$/, "$${PLIST.letsencrypt}&"); }
PRINT_PLIST_AWK+=	{ gsub(/^man\/man1\/lefh\.1$$/, "$${PLIST.letsencrypt}&"); }
PRINT_PLIST_AWK+=	{ gsub(/^sbin\/lefh$$/, "$${PLIST.letsencrypt}&"); }
PRINT_PLIST_AWK+=	{ gsub(/^${EGDIR:S/\//\\\//g}\/letsencrypt.conf$$/, "$${PLIST.letsencrypt}&"); }

.for f in ${CONFIG_FILES}
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor
.if !empty(PKG_OPTIONS:Mletsencrypt)
CONF_FILES+=	${EGDIR}/letsencrypt.conf ${PKG_SYSCONFDIR}/letsencrypt.conf
.endif
CONF_FILES+=	${EGDIR}/index.html.sample ${HIAWATHA_WEBROOT}/index.html

.include "../../mk/bsd.prefs.mk"

post-extract:
.if !empty(HIAWATHA_REPLACE_MBEDTLS:Myes)
.for sdir in cmake include library
	rm -r ${WRKSRC}/mbedtls/${sdir}
	cp -R ${WRKDIR}/mbedtls-${MTVER}/${sdir} ${WRKSRC}/mbedtls/
.endfor
	cp ${WRKDIR}/mbedtls-${MTVER}/ChangeLog ${WRKSRC}/mbedtls/
.endif

post-install:
.if !empty(PKG_OPTIONS:Mmbedtls-private)
	rm -r ${DESTDIR}${PREFIX}/include
	rm ${DESTDIR}${PREFIX}/lib/hiawatha/*.a
.endif
.if empty(PKG_OPTIONS:Mletsencrypt)
	rm -r ${DESTDIR}${PREFIX}/lib/hiawatha
	rm ${DESTDIR}${PREFIX}/sbin/lefh
	rm ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/lefh.1
.else
	${INSTALL_DATA} ${WRKSRC}/letsencrypt.conf \
		${DESTDIR}${PREFIX}/${EGDIR}/letsencrypt.conf
.endif
.for f in ${CONFIG_FILES}
	${INSTALL_DATA} ${WRKSRC}/config/${f} ${DESTDIR}${PREFIX}/${EGDIR}/${f}
.endfor
.if !empty(PKG_OPTIONS:Murltoolkit)
	${INSTALL_DATA} ${WRKSRC}/config/toolkit.conf \
		${DESTDIR}${PREFIX}/${EGDIR}/toolkit.conf
.endif
.if !empty(PKG_OPTIONS:Mxslt)
	${INSTALL_DATA} ${WRKSRC}/config/error.xslt \
		${DESTDIR}${PREFIX}/${EGDIR}/error.xslt
	${INSTALL_DATA} ${WRKSRC}/config/index.xslt \
		${DESTDIR}${PREFIX}/${EGDIR}/index.xslt
.endif
	${INSTALL_DATA} ${WRKSRC}/extra/index.html \
		${DESTDIR}${PREFIX}/${EGDIR}/index.html.sample

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../devel/cmake/build.mk"

.include "../../mk/bsd.pkg.mk"
