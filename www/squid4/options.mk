# $NetBSD: options.mk,v 1.4 2020/06/21 16:05:55 taca Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.squid4
PKG_SUPPORTED_OPTIONS=		inet6 snmp squid-backend-aufs \
				squid-backend-diskd squid-backend-rock \
				squid-backend-ufs squid-ecap squid-esi \
				squid-unlinkd squid-kerberos-helper \
				squid-ldap-helper squid-pam-helper
PKG_OPTIONS_REQUIRED_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=		openssl gnutls
PKG_OPTIONS_LEGACY_OPTS+=	diskd:squid-backend-diskd \
				ecap:squid-ecap esi:squid-esi \
				null:squid-backend-null ufs:squid-backend-ufs \
				linux-netfilter:squid-netfilter \
				ipf-transparent:squid-ipf \
				pf-transparent:squid-pf unlinkd:squid-unlinkd \
				arp-acl:squid-arp-acl \
				pam-helper:squid-pam-helper

PLIST_VARS+=	ba_LDAP ba_NCSA ba_PAM ba_getpwnam
PLIST_VARS+=	da_LDAP da_file diskd
PLIST_VARS+=	eacl_LDAP_group eacl_file_userip eacl_unix_group
PLIST_VARS+=	openssl ta_kerberos unlinkd

PKG_SUGGESTED_OPTIONS=	inet6 openssl snmp squid-backend-aufs \
			squid-backend-diskd squid-backend-ufs \
			squid-esi squid-pam-helper squid-unlinkd

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
PKG_SUPPORTED_OPTIONS+=	squid-netfilter
.endif

# some release of NetBSD lacks <ipl.h> header of IP Filter 4.x
.if ${OPSYS} != "NetBSD" || ${OS_VERSION:M[01].*} || exists(/usr/include/netinet/ipl.h)
PKG_SUPPORTED_OPTIONS+=	squid-ipf
.endif

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD" || \
    ${OPSYS} == "Darwin" || ${OPSYS} == "DragonFly"
PKG_SUPPORTED_OPTIONS+=	squid-pf
.endif

.if (${OPSYS} == "NetBSD") && \
	!empty(PKG_SUPPORTED_OPTIONS:Msquid-ipf)
PKG_SUGGESTED_OPTIONS+=	squid-ipf
.endif

PKG_SUGGESTED_OPTIONS.OpenBSD+=	squid-pf

PKG_SUPPORTED_OPTIONS.Darwin+=	squid-ipfw
PKG_SUGGESTED_OPTIONS.Darwin+=	squid-ipfw

# limited platform support squid-arp-acl
.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD" || ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
PKG_SUPPORTED_OPTIONS+=	squid-arp-acl
.endif

.include "../../mk/bsd.options.mk"

# Note: NIS helper cannot be build; it requires crypt.h header file.
SQUID_BASIC_AUTH_HELPERS?=	DB NCSA PAM fake getpwnam
SQUID_DIGEST_AUTH_HELPERS?=	file
SQUID_NTLM_AUTH_HELPERS?=	SMB_LM fake
SQUID_EXTERNAL_ACL_HELPERS?=	file_userip unix_group

# squid's code has preference as:
#	squid-ipf > squid-pf > squid-netfilter
# So, options.mk introduce preference as:
#	squid-netfilter > squid-pf > squid-ipf
.if !empty(PKG_OPTIONS:Msquid-netfilter)
CONFIGURE_ARGS+=	--enable-linux-netfilter
.elif !empty(PKG_OPTIONS:Msquid-pf)
CONFIGURE_ARGS+=	--enable-pf-transparent
.  if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-nat-devpf
.  endif
.elif !empty(PKG_OPTIONS:Msquid-ipf)
CONFIGURE_ARGS+=	--enable-ipf-transparent
.elif !empty(PKG_OPTIONS:Msquid-ipfw)
CONFIGURE_ARGS+=	--enable-ipfw-transparent
.endif

.if !empty(PKG_OPTIONS:Msquid-arp-acl)
CONFIGURE_ARGS+=	--enable-arp-acl
.endif

.if !empty(PKG_OPTIONS:Msquid-ecap)
CONFIGURE_ARGS+=	--enable-ecap
USE_TOOLS+=		pkg-config
CHECK_WRKREF_SKIP+=	sbin/squid
USE_LANGUAGES+=		c++11
.include "../../www/libecap/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ecap
.endif

.if !empty(PKG_OPTIONS:Msquid-esi)
CONFIGURE_ARGS+=	--enable-esi
.include "../../textproc/expat/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-esi
.endif

.if !empty(PKG_SUPPORTED_OPTIONS:Minet6) && empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Msquid-kerberos-helper)
.include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ENV+=		ac_cv_path_krb5_config=${KRB5_CONFIG:Q}
SQUID_NEGOTIATE_AUTH_HELPERS+=	kerberos
.else
CONFIGURE_ENV+=		ac_cv_path_krb5_config=no
CONFIGURE_ARGS+=	--without-mit-krb5
CONFIGURE_ARGS+=	--without-heimdal-krb5
.endif

.if !empty(PKG_OPTIONS:Msquid-ldap-helper)
.include "../../databases/openldap-client/buildlink3.mk"
SQUID_BASIC_AUTH_HELPERS+=	LDAP
SQUID_DIGEST_AUTH_HELPERS+=	LDAP
SQUID_EXTERNAL_ACL_HELPERS+=	LDAP_group
.endif

.if !empty(PKG_OPTIONS:Msquid-pam-helper)
.  include "../../mk/pam.buildlink3.mk"
SQUID_BASIC_AUTH_HELPERS+=	PAM
.endif

.if !empty(PKG_OPTIONS:Msnmp)
CONFIGURE_ARGS+=	--enable-snmp
.else
CONFIGURE_ARGS+=	--disable-snmp
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
CONFIGURE_ARGS+=	--enable-ssl-crtd --without-gnutls
.  include "../../security/openssl/buildlink3.mk"
PLIST.openssl=		yes
.endif

.if !empty(PKG_OPTIONS:Mgnutls)
CONFIGURE_ARGS+=	--with-gnutls=${PREFIX:Q}
CONFIGURE_ARGS+=	--without-openssl
.  include "../../security/gnutls/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msquid-backend-aufs)
SQUID_BACKENDS+=	aufs
.  include "../../mk/pthread.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msquid-backend-diskd)
SQUID_BACKENDS+=	diskd
PLIST.diskd=		yes
.endif

.if !empty(PKG_OPTIONS:Msquid-backend-rock)
SQUID_BACKENDS+=	rock
.endif

.if !empty(PKG_OPTIONS:Msquid-backend-ufs)
SQUID_BACKENDS+=	ufs
.endif

.if !empty(PKG_OPTIONS:Msquid-unlinkd)
PLIST.unlinkd=		yes
.else
CONFIGURE_ARGS+=	--disable-unlinkd
.endif

.if empty(SQUID_BASIC_AUTH_HELPERS)
CONFIGURE_ARGS+=	--disable-auth-basic
.else
CONFIGURE_ARGS+=	--enable-auth-basic=${SQUID_BASIC_AUTH_HELPERS:Q}
.  for i in ${SQUID_BASIC_AUTH_HELPERS}
PLIST.ba_${i}=		yes
.  endfor
.PHONY: squid-enable-helper-basic_auth
pre-configure: squid-enable-helper-basic_auth
squid-enable-helper-basic_auth:
.  for i in ${SQUID_BASIC_AUTH_HELPERS}
#	${ECHO} "exit 0" > ${WRKSRC}/src/auth/basic/${i}/config.test
.  endfor
.endif

.if empty(SQUID_DIGEST_AUTH_HELPERS)
CONFIGURE_ARGS+=	--disable-auth-digest
.else
CONFIGURE_ARGS+=	--enable-auth-digest=${SQUID_DIGEST_AUTH_HELPERS:Q}
.  for i in ${SQUID_DIGEST_AUTH_HELPERS}
PLIST.da_${i}=		yes
.  endfor
pre-configure:
.  for i in ${SQUID_DIGEST_AUTH_HELPERS}
#	${ECHO} "exit 0" > ${WRKSRC}/src/auth/digest/${i}/config.test
.  endfor
.endif

.if empty(SQUID_NEGOTIATE_AUTH_HELPERS)
CONFIGURE_ARGS+=	--disable-auth-negotiate
.else
CONFIGURE_ARGS+=	--enable-auth-negotiate=${SQUID_NEGOTIATE_AUTH_HELPERS:Q}
.  for i in ${SQUID_NEGOTIATE_AUTH_HELPERS}
PLIST.ta_${i}=		yes
.  endfor
.PHONY: squid-enable-helper-negotiate_auth
pre-configure: squid-enable-helper-negotiate_auth
squid-enable-helper-negotiate_auth:
.  for i in ${SQUID_NEGOTIATE_AUTH_HELPERS}
#	${ECHO} "exit 0" > ${WRKSRC}/src/auth/negotiate/${i}/config.test
.  endfor
.endif

.if empty(SQUID_NTLM_AUTH_HELPERS)
CONFIGURE_ARGS+=	--disable-auth-ntlm
.else
CONFIGURE_ARGS+=	--enable-auth-ntlm=${SQUID_NTLM_AUTH_HELPERS:Q}
.PHONY: squid-enable-helper-ntlm_auth
pre-configure: squid-enable-helper-ntlm_auth
squid-enable-helper-ntlm_auth:
.  for i in ${SQUID_NTLM_AUTH_HELPERS}
#	${ECHO} "exit 0" > ${WRKSRC}/src/auth/ntlm/${i}/config.test
.  endfor
.endif

.if empty(SQUID_EXTERNAL_ACL_HELPERS)
CONFIGURE_ARGS+=	--disable-external-acl-helpers
.else
CONFIGURE_ARGS+=	--enable-external-acl-helpers=${SQUID_EXTERNAL_ACL_HELPERS:Q}
.  for i in ${SQUID_EXTERNAL_ACL_HELPERS}
PLIST.eacl_${i}=	yes
.  endfor
.PHONY: squid-enable-helper-external_acl
pre-configure: squid-enable-helper-external_acl
squid-enable-helper-external_acl:
.  for i in ${SQUID_EXTERNAL_ACL_HELPERS}
#	${ECHO} "exit 0" > ${WRKSRC}/src/acl/external/${i}/config.test
.  endfor
.endif
