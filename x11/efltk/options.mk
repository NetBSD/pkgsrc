# $NetBSD: options.mk,v 1.2 2006/02/18 14:07:54 joerg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.efltk
PKG_SUPPORTED_OPTIONS=	opengl mysql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopengl)
PLIST_SUBST+=		OPENGL=
CONFIGURE_ARGS+=	--enable-opengl
MAKE_ENV+=		HAVE_OPENGL=yes
.  include "../../graphics/MesaLib/buildlink3.mk"
.else
PLIST_SUBST+=		OPENGL="@comment "
CONFIGURE_ARGS+=	--disable-opengl
MAKE_ENV+=		HAVE_OPENGL=no
.endif

.if !empty(PKG_OPTIONS:Mmysql)
PLIST_SUBST+=		MYSQL=
CONFIGURE_ARGS+=	--enable-mysql
.  include "../../mk/mysql.buildlink3.mk"
.else
PLIST_SUBST+=		MYSQL="@comment "
CONFIGURE_ARGS+=	--disable-mysql
.endif
