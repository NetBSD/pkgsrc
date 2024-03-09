# $NetBSD: options.mk,v 1.4 2024/03/09 23:59:38 vins Exp $

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

PAMDIR=			share/examples/pam.d
MAKE_DIRS+=		${PAMDIR}

INSTALLATION_DIRS+=	${PAMDIR}

PLIST.pam=		yes
PLIST_SUBST+=		PAMDIR=${PAMDIR:Q}

.PHONY:	pam-install

pam-install:
	${INSTALL_DATA} ${WRKSRC}/lib/pam/libpam/pam.conf       \
		${DESTDIR}${PREFIX}/${PAMDIR}/cde
.  for i in dtlogin dtsession
	${INSTALL_DATA} ${WRKSRC}/programs/${i}/config/${i}	\
		${DESTDIR}${PREFIX}/${PAMDIR}
.  endfor
.else

CONFIGURE_ENV+=		ac_cv_lib_pam_pam_start=no
SPECIAL_PERMS+=		${PREFIX}/dt/bin/dtsession ${SETUID_ROOT_PERMS}
.endif
