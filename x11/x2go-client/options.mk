# $NetBSD: options.mk,v 1.1 2021/02/24 18:39:30 hauke Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.x2go-client
PKG_SUPPORTED_OPTIONS=	ldap pulseaudio

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mldap)
CPPFLAGS+=		-DUSELDAP
LIBS+=			-lldap
.  include "../../databases/openldap-client/buildlink3.mk"
.else
# nothing
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.else
# nothing
.endif
