# $NetBSD: options.mk,v 1.14 2022/02/18 15:18:23 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xscreensaver
PKG_SUPPORTED_OPTIONS=	pam
PKG_SUGGESTED_OPTIONS=	# pam # needs fixing, complains about missing /etc/pam.d/xscreensaver

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
CONFIGURE_ARGS+=	--without-shadow
.  if ${OPSYS} == "NetBSD"
# needed to read shadow passwords
DEPENDS+=	pam-pwauth_suid-[0-9]*:../../security/pam-pwauth_suid
.  endif
.else
CONFIGURE_ARGS+=	--without-pam
# configure should figure out
#CONFIGURE_ARGS+=	--without-shadow
SPECIAL_PERMS+=		bin/xscreensaver ${SETUID_ROOT_PERMS}
.endif
