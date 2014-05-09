# $NetBSD: options.mk,v 1.10 2014/05/09 22:45:15 marino Exp $


# xmlada is built-in (not optional) due to gprbuild dependency
# zlib is built-in because it's mandatory.  It even comes with AWS.
# ASIS is not supported right now (custom build, requires part of GNAT)

# The "ipv6" option effectively disabled IPv4 support, so it
# should not be switched on per default even on systems which
# support IPv6. For that reason, the option name is not "inet6".

PKG_OPTIONS_VAR=	PKG_OPTIONS.aws
PKG_OPTIONS_OPTIONAL_GROUPS=	slayer
PKG_OPTIONS_GROUP.slayer=	ssl gnutls
PKG_SUPPORTED_OPTIONS=	ldap inet6 debug relocatable
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

CONFIGURE_ARGS+=	GCC=ada
CONFIGURE_ARGS+=	PROCESSORS=${MAKE_JOBS}
CONFIGURE_ARGS+=	PYTHON=python${PYVERSSUFFIX}
CONFIGURE_ARGS+=	XMLADA=true
CONFIGURE_ARGS+=	prefix=${PREFIX}
DOTBUILD=		release

# The system libgcc is from version 4.1 which doesn't include the symbol
# _Unwind_GetIPInfo.  If AWS uses the system zlib or if it's configured to use
# SSL the search path /usr/lib is inserted in the gnatmake/gprbuild
# instructions and the system libgcc.a is picked up instead of
# /usr/pkg/lib/libgcc.a.  This is a bug confirmed by Adacore and an internal
# bug report has been generated.  In the meantime, this means AWS can't be
# configured for HTTPS on NetBSD, and that zlib must be built from scratch on
# NetBSD until NetBSD upgrades it's libgcc or until a new GNAT and GPRBuild
# are delivered that don't have this bug.

.if $(OPSYS) == NetBSD
CONFIGURE_ARGS+=	ZLIB=false
.else
CONFIGURE_ARGS+=	ZLIB=true
.endif

###################
##  SSL Support  ##
###################

.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+= SOCKET=openssl
.endif

.if !empty(PKG_OPTIONS:Mgnutls)
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+= SOCKET=gnutls
.endif


####################
##  LDAP Support  ##
####################

.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+= LDAP=true
.include "../../databases/openldap-client/buildlink3.mk"
.endif

####################
##  IPv6 Support  ##
####################

PLIST_VARS+= ipv6 noipv6
.if !empty(PKG_OPTIONS:Mipv6)
CONFIGURE_ARGS+= IPv6=true
.endif

#####################
##  Debug Support  ##
#####################

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+= DEBUG=true
DOTBUILD=debug
.endif

##############################
##  Shared Runtime Library  ##
##############################

#.if !empty(PKG_OPTIONS:Mdisable-shared-rt)
CONFIGURE_ARGS+= ENABLE_SHARED=false
#.endif

############################
##  Default Library Type  ##
############################

.if !empty(PKG_OPTIONS:Mrelocatable)
CONFIGURE_ARGS+= DEFAULT_LIBRARY_TYPE=relocatable
.endif
