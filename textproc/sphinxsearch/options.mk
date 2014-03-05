# $NetBSD: options.mk,v 1.1 2014/03/05 13:44:23 fhajny Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.sphinx-search
PKG_OPTIONS_NONEMPTY_SETS=	db
PKG_OPTIONS_SET.db=		mysql pgsql
PKG_SUPPORTED_OPTIONS=		#
PKG_SUGGESTED_OPTIONS=		mysql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--with-mysql
.  include "../../mk/mysql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--with-pgsql
.  include "../../mk/pgsql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-pgsql
.endif
