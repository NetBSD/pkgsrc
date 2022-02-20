# $NetBSD: options.mk,v 1.16 2022/02/20 17:27:18 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xscreensaver
PKG_SUPPORTED_OPTIONS=	pam
PKG_SUGGESTED_OPTIONS=	# pam

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
CONFIGURE_ARGS+=	--without-shadow
.  if ${OPSYS} == "NetBSD"
# needed to read shadow passwords
# please follow pam-pwauth_suid's MESSAGE file to enable unlocking
DEPENDS+=	pam-pwauth_suid-[0-9]*:../../security/pam-pwauth_suid
.  endif
.else
CONFIGURE_ARGS+=	--without-pam
# configure should figure out
#CONFIGURE_ARGS+=	--without-shadow
SPECIAL_PERMS+=		libexec/xscreensaver/xscreensaver-auth ${SETUID_ROOT_PERMS}
.endif
