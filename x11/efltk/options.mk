# $NetBSD: options.mk,v 1.1.1.1 2005/09/02 14:41:37 xtraeme Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.efltk
PKG_SUPPORTED_OPTIONS=	opengl mysql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopengl)
PLIST_SUBST+=		OPENGL=
CONFIGURE_ARGS+=	--enable-opengl
.  include "../../graphics/MesaLib/buildlink3.mk"
.else
PLIST_SUBST+=		OPENGL="@comment "
CONFIGURE_ARGS+=	--disable-opengl
.endif

.if !empty(PKG_OPTIONS:Mmysql)
PLIST_SUBST+=		MYSQL=
CONFIGURE_ARGS+=	--enable-mysql
.  include "../../mk/mysql.buildlink3.mk"
.else
PLIST_SUBST+=		MYSQL="@comment "
CONFIGURE_ARGS+=	--disable-mysql
.endif
