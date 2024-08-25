# $NetBSD: options.mk,v 1.7 2024/08/25 06:19:19 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kde-runtime4
PKG_SUPPORTED_OPTIONS=	samba alsa pulseaudio
#PKG_SUGGESTED_OPTIONS=	samba

PKG_SUGGESTED_OPTIONS.Linux+=	alsa

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	smb
.if !empty(PKG_OPTIONS:Msamba)
.include "../../net/samba/buildlink3.mk"
#CMAKE_CONFIGURE_ARGS+=	-DSAMBA_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.samba}/include
#CMAKE_CONFIGURE_ARGS+=	-DSAMBA_LIBRARIES:FILEPATH=${BUILDLINK_PREFIX.samba}/lib/samba
PLIST.smb=	yes
.endif

.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_ALSA=OFF
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_PulseAudio:BOOL=OFF
.endif
