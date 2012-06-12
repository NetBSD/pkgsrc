# $NetBSD: options.mk,v 1.2 2012/06/12 15:46:04 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gdm
PKG_SUPPORTED_OPTIONS=	consolekit inet6 pam
PKG_SUGGESTED_OPTIONS=	consolekit inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mconsolekit)
CONFIGURE_ARGS+=	--with-console-kit=yes
.include "../../sysutils/consolekit/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-console-kit=no
.endif

PLIST_VARS+=		pam
.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-authentication-scheme=pam
.  if ${PAM_TYPE} == "linux-pam"
PLIST.pam=		yes
.  endif
.elif exists(/etc/shadow)
CONFIGURE_ARGS+=	--enable-authentication-scheme=shadow
.else
CONFIGURE_ARGS+=	--enable-authentication-scheme=crypt
.endif
