# $NetBSD: options.mk,v 1.1.1.1 2009/02/12 00:26:59 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.apache-roller

PKG_OPTIONS_OPTIONAL_GROUPS=	jdbc
PKG_OPTIONS_GROUP.jdbc=		jdbc-mysql5 jdbc-mysql31

PKG_SUPPORTED_OPTIONS=	jdbc-mysql31 jdbc-mysql5
PKG_SUGGESTED_OPTIONS=	jdbc-mysql31

.include "../../mk/bsd.options.mk"

###
### jdbc mysql v5.0 or v3.1 driver
###
.if !empty(PKG_OPTIONS:Mjdbc-mysql31)
DEPENDS+=	jdbc-mysql>=3:../../databases/jdbc-mysql31
.endif

.if !empty(PKG_OPTIONS:Mjdbc-mysql5)
DEPENDS+=	jdbc-mysql>=5:../../databases/jdbc-mysql5
.endif
