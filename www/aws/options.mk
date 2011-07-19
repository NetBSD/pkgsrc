# $NetBSD: options.mk,v 1.3 2011/07/19 19:56:37 drochner Exp $


# xmlada is built-in (not optional) due to gprbuild dependency
# zlib is built-in because it's mandatory.  It even comes with AWS.
# ASIS is not supported right now (custom build, requires part of GNAT)

# The "ipv6" option effectively disabled IPv4 support, so it
# should not be switched on per default even on systems which
# support IPv6. For that reason, the option name is not "inet6".

PKG_OPTIONS_VAR=	PKG_OPTIONS.aws
PKG_SUPPORTED_OPTIONS=	ssl ldap ipv6 debug disable-shared-rt relocatable
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

CONFIGURE_ARGS+=	GCC=gnatgcc
CONFIGURE_ARGS+=	PROCESSORS=1
CONFIGURE_ARGS+=	PYTHON=python${PYVERSSUFFIX}
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

.if $(OPSYS) == "NetBSD"
CONFIGURE_ARGS+=	ZLIB=false
.endif

###################
##  SSL Support  ##
###################

.if !empty(PKG_OPTIONS:Mssl)
.if $(OPSYS) == "NetBSD"
MESSAGE_SRC=	MESSAGE_NETBSD_SSL
.else
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+= SOCKET=openssl
.endif
.endif

####################
##  LDAP Support  ##
####################

.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+= LDAP=true
DEPENDS+= openldap>=2.4:../../databases/openldap
.endif

####################
##  IPv6 Support  ##
####################

PLIST_VARS+= ipv6 noipv6
.if !empty(PKG_OPTIONS:Mipv6)
CONFIGURE_ARGS+= IPv6=true
PLIST.ipv6= yes
.else
PLIST.noipv6= yes
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

.if !empty(PKG_OPTIONS:Mdisable-shared-rt)
CONFIGURE_ARGS+= ENABLE_SHARED=false
.endif

############################
##  Default Library Type  ##
############################

.if !empty(PKG_OPTIONS:Mrelocatable)
CONFIGURE_ARGS+= DEFAULT_LIBRARY_TYPE=relocatable
.endif
