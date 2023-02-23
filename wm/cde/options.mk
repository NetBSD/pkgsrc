# $NetBSD: options.mk,v 1.2 2023/02/23 19:10:06 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.cde

PKG_SUPPORTED_OPTIONS=	nls pam
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "Linux"
# upstream only supports pam on linux and netbsd
PKG_SUGGESTED_OPTIONS=	pam
.else
PKG_SUGGESTED_OPTIONS=
.endif

PLIST_VARS+=		nls pam

.include "../../mk/bsd.options.mk"

#
# Native Language Support
#
.if	!empty(PKG_OPTIONS:Mnls)
.  include "../../devel/gettext-tools/buildlink3.mk"
USE_TOOLS+=		msgfmt

.  for lang in french german italian japanese spanish
CONFIGURE_ARGS+=	--enable-${lang}
.  endfor

PLIST.nls=		yes
.endif

#
# PAM support
#
.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
DEPENDS+=		pam-pwauth_suid-[0-9]*:../../security/pam-pwauth_suid

CONFIGURE_ENV+=		ac_cv_lib_pam_pam_start=yes

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES+=		${EGDIR}/pam.d/cde \
			${PKG_SYSCONFDIR}/pam.d/cde

MAKE_DIRS+=		${PKG_SYSCONFDIR}/pam.d
INSTALLATION_DIRS+=	share/examples/${PKGBASE}/pam.d

PLIST.pam=		yes

pre-install:
	${INSTALL_DATA} ${WRKSRC}/lib/pam/libpam/pam.conf       \
		${DESTDIR}${EGDIR}/pam.d/cde
.else
CONFIGURE_ENV+=		ac_cv_lib_pam_pam_start=no
SPECIAL_PERMS+=		${PREFIX}/dt/bin/dtsession ${SETUID_ROOT_PERMS}
.endif
