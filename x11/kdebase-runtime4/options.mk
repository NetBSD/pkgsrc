# $NetBSD: options.mk,v 1.1.1.1 2009/10/02 19:30:13 markd Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kdebase-runtime4
PKG_SUPPORTED_OPTIONS=  samba

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	smb
.if !empty(PKG_OPTIONS:Msamba)
.include "../../net/samba/buildlink3.mk"
CMAKE_ARGS+=	-DSAMBA_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.samba}/include
CMAKE_ARGS+=	-DSAMBA_LIBRARIES:FILEPATH=${BUILDLINK_PREFIX.samba}/lib/samba
PLIST.smb=	yes
.endif
