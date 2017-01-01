# $NetBSD: options.mk,v 1.2 2017/01/01 18:19:58 spz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.apache-roller

PKG_OPTIONS_OPTIONAL_GROUPS=	jdbc
PKG_OPTIONS_GROUP.jdbc=		jdbc-mysql51 jdbc-mysql5 jdbc-mysql31

PKG_SUPPORTED_OPTIONS=	jdbc-mysql31 jdbc-mysql5 jdbc-mysql51
PKG_SUGGESTED_OPTIONS=	jdbc-mysql51

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

.if !empty(PKG_OPTIONS:Mjdbc-mysql51)
DEPENDS+=	jdbc-mysql>=5.1:../../databases/jdbc-mysql51
.endif
