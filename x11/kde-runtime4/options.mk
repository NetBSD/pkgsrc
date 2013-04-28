# $NetBSD: options.mk,v 1.3 2013/04/28 03:18:18 markd Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kde-runtime4
PKG_SUPPORTED_OPTIONS=	samba alsa
PKG_SUGGESTED_OPTIONS=	samba

.if ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS+= alsa
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	smb
.if !empty(PKG_OPTIONS:Msamba)
.include "../../net/samba/buildlink3.mk"
#CMAKE_ARGS+=	-DSAMBA_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.samba}/include
#CMAKE_ARGS+=	-DSAMBA_LIBRARIES:FILEPATH=${BUILDLINK_PREFIX.samba}/lib/samba
PLIST.smb=	yes
.endif

.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_ALSA=OFF
.endif
