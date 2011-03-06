# $NetBSD: options.mk,v 1.2 2011/03/06 16:04:33 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kdebase-workspace
PKG_SUPPORTED_OPTIONS=	inet6
#PKG_SUPPORTED_OPTIONS=	inet6 sasl samba debug pam
#PKG_SUGGESTED_OPTIONS=	sasl

.include "../../mk/bsd.options.mk"

#.if !empty(PKG_OPTIONS:Msamba)
#.include "../../net/samba/buildlink3.mk"
#LIBS+=			-L${BUILDLINK_PREFIX.samba}/lib/samba ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.samba}/lib/samba
#PLIST_SUBST+=		HAVE_SMB=""
#.else
#PLIST_SUBST+=		HAVE_SMB="@comment "
#.endif

#.if !empty(PKG_OPTIONS:Mdebug)
#CC+=			-ggdb
#CXX+=			-ggdb
#CONFIGURE_ARGS+=	--enable-debug=full
#CONFIGURE_ENV+=		INSTALL_STRIP_FLAG=
#INSTALL_UNSTRIPPED=	yes
#.endif

#.if !empty(PKG_OPTIONS:Mpam)
#.  include "../../mk/pam.buildlink3.mk"
#CONFIGURE_ARGS+=	--with-pam
#.else
#CONFIGURE_ARGS+=	--without-pam
#.endif

#.if !empty(PKG_OPTIONS:Msasl)
#.include "../../security/cyrus-sasl/buildlink3.mk"
#.endif
