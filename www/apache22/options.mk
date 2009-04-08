# $NetBSD: options.mk,v 1.6 2009/04/08 17:03:25 tron Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.apache
PKG_SUPPORTED_OPTIONS=	apache-shared-modules suexec

.include "../../mk/bsd.options.mk"

# APACHE_MODULES are the modules that are linked statically into the
# apache httpd executable.
#
PLIST_VARS+=		all-shared
.if !empty(PKG_OPTIONS:Mapache-shared-modules)
CONFIGURE_ARGS+=        --enable-mods-shared=${DFLT_APACHE_MODULES:Q}
PLIST.all-shared=	yes
.else
CONFIGURE_ARGS+=        --enable-modules=${APACHE_MODULES:Q}
.endif
BUILD_DEFS+=            APACHE_MODULES

PLIST_VARS+=		suexec
.if !empty(PKG_OPTIONS:Msuexec)
BUILD_DEFS+=		APACHE_SUEXEC_PATH
BUILD_DEFS+=		APACHE_SUEXEC_DOCROOT APACHE_SUEXEC_LOGFILE

APACHE_SUEXEC_DOCROOT?=	${PREFIX}/share/httpd/htdocs
APACHE_SUEXEC_PATH=	/bin:/usr/bin:${PREFIX}/bin:/usr/local/bin
APACHE_SUEXEC_LOGFILE?=	${VARBASE}/log/httpd/suexec.log
APACHE_SUEXEC_CONFIGURE_ARGS+=						\
	--with-suexec-bin=${PREFIX}/sbin/suexec				\
	--with-suexec-caller=${APACHE_USER}				\
	--with-suexec-safepath='${APACHE_SUEXEC_PATH:Q}'		\
	--with-suexec-docroot=${APACHE_SUEXEC_DOCROOT:Q}		\
	--with-suexec-logfile=${APACHE_SUEXEC_LOGFILE:Q}

APACHE_MODULES+=        suexec
CONFIGURE_ARGS+=        ${APACHE_SUEXEC_CONFIGURE_ARGS:M--with-suexec-*}
BUILD_DEFS+=            APACHE_SUEXEC_CONFIGURE_ARGS
BUILD_TARGET=		all suexec
PLIST.suexec=		yes
SPECIAL_PERMS+=		sbin/suexec ${REAL_ROOT_USER} ${APACHE_GROUP} 4510
.endif
