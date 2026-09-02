# $NetBSD: Makefile,v 1.74 2026/09/02 19:05:01 wiz Exp $

DISTNAME=	${PKGNAME_NOREV}-stable-src
PKGNAME=	privoxy-4.2.0
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://www.privoxy.org/sf-download-mirror/Sources/${PKGVERSION_NOREV}%20(stable)/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.privoxy.org/
COMMENT=	Web proxy with advanced filtering capabilities
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}-stable

.include "options.mk"
.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR=	privoxy
PRIVOXY_EGDIR=		${PREFIX}/share/examples/${PKGBASE}
PRIVOXY_DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
PRIVOXY_LOGDIR=		${VARBASE}/log/privoxy

USE_TOOLS+=		gmake mktemp autoconf autoheader perl:run

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	config man/privoxy.8 man/uagen.1 tools/uagen.pl
SUBST_VARS.paths=	PREFIX VARBASE PKG_SYSCONFDIR PRIVOXY_LOGDIR PRIVOXY_DOCDIR
SUBST_STAGE.paths=	pre-configure

REPLACE_PERL+=		tools/privoxy-log-parser.pl \
			tools/privoxy-regression-test.pl \
			tools/url-pattern-translator.pl \
			tools/uagen.pl

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PRIVOXY_EGDIR}
CONFIGURE_ARGS+=	--with-user=${PRIVOXY_USER:Q}
CONFIGURE_ARGS+=	--with-group=${PRIVOXY_GROUP:Q}

MAKE_FILE=		GNUmakefile

BUILD_DEFS+=			VARBASE
PRIVOXY_USER=			privoxy
PRIVOXY_GROUP=			privoxy
PRIVOXY_HOME=			${VARBASE}/lib/privoxy
PKG_USERS_VARS+=		PRIVOXY_USER
PKG_GROUPS_VARS+=		PRIVOXY_GROUP
PKG_GROUPS=			${PRIVOXY_GROUP}
PKG_USERS=			${PRIVOXY_USER}:${PRIVOXY_GROUP}
PKG_GECOS.${PRIVOXY_USER}=	Privoxy user

OWN_DIRS_PERMS+=	${PRIVOXY_HOME} ${PRIVOXY_USER} ${PRIVOXY_GROUP} 0770

FILES_SUBST+=		PRIVOXY_USER=${PRIVOXY_USER:Q}
.if ${INIT_SYSTEM} == "rc.d"
RCD_SCRIPTS+=		privoxy
.endif

USER_GROUP=		${PRIVOXY_USER} ${PRIVOXY_GROUP}

OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/templates ${USER_GROUP} 0755

PRIVOXY_CONF_FILES=	config default.action default.filter \
			match-all.action trust user.action user.filter

PRIVOXY_TEMPLATE_FILES=	blocked cgi-error-404 cgi-error-bad-param \
			cgi-error-disabled cgi-error-file \
			cgi-error-file-read-only cgi-error-modified \
			cgi-error-parse cgi-style.css client-tags \
			connect-failed connection-timeout default \
			edit-actions-add-url-form edit-actions-for-url \
			edit-actions-for-url-filter \
			edit-actions-for-url-string-action mod-title \
			edit-actions-list edit-actions-list-button \
			edit-actions-list-section edit-actions-list-url \
			edit-actions-remove-url-form edit-actions-url-form \
			forwarding-failed mod-local-help \
			mod-support-and-service mod-unstable-warning \
			no-server-data no-such-domain show-request show-status \
			show-status-file show-url-info toggle toggle-mini \
			untrusted url-info-osd.xml wpad.dat

.for f in ${PRIVOXY_CONF_FILES}
CONF_FILES+=		${PRIVOXY_EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

.for f in ${PRIVOXY_TEMPLATE_FILES}
CONF_FILES+=		${PRIVOXY_EGDIR}/templates/${f} ${PKG_SYSCONFDIR}/templates/${f}
.endfor

OWN_DIRS_PERMS+=	${PRIVOXY_LOGDIR} ${USER_GROUP} 0755

pre-configure:
	cd ${WRKSRC} && autoheader && autoconf

.include "../../devel/pcre2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
