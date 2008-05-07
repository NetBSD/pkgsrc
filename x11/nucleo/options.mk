PKG_OPTIONS_VAR=	PKG_OPTIONS.nucleo
PKG_SUPPORTED_OPTIONS=	gnutls # qt4
PKG_SUGGESTED_OPTIONS=	gnutls

.include "../../mk/bsd.options.mk"

###
### XXX The build currently fails.  This needs to be investigated.
###
#.if !empty(PKG_OPTIONS:Mqt4)
#CONFIGURE_ARGS+=	--with-qt
#PLIST_VARS+=		qt4
#.  include "../../x11/qt4-libs/buildlink3.mk"
#.else
#CONFIGURE_ARGS+=	--without-qt
#.endif

.if !empty(PKG_OPTIONS:Mgnutls)
CONFIGURE_ARGS+=	--with-gnutls
PLIST.gnutls=		yes
.  include "../../security/gnutls/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gnutls
PLIST.gnutls=		no
.endif
