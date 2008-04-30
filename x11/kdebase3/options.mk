# $NetBSD: options.mk,v 1.5 2008/04/30 12:20:09 xtraeme Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kdebase
PKG_SUPPORTED_OPTIONS=	inet6 sasl samba debug pam composite
PKG_SUGGESTED_OPTIONS=	sasl

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		composite
.if !empty(PKG_OPTIONS:Mcomposite)
CONFIGURE_ARGS+=	--with-composite
PLIST.composite=	yes
.include "../../x11/libXcomposite/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-composite
.endif

PLIST_VARS+=		smb
.if !empty(PKG_OPTIONS:Msamba)
.include "../../net/samba/buildlink3.mk"
LIBS+=			-L${BUILDLINK_PREFIX.samba}/lib/samba ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.samba}/lib/samba
PLIST.smb=		yes
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CC+=			-ggdb
CXX+=			-ggdb
CONFIGURE_ARGS+=	--enable-debug=full
CONFIGURE_ENV+=		INSTALL_STRIP_FLAG=
INSTALL_UNSTRIPPED=	yes
.endif

.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
.else
CONFIGURE_ARGS+=	--without-pam
.endif

.if !empty(PKG_OPTIONS:Msasl)
.include "../../security/cyrus-sasl/buildlink3.mk"
.endif
