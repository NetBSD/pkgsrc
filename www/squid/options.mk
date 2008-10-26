# $NetBSD: options.mk,v 1.14.4.1 2008/10/26 14:42:30 tron Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.squid
PKG_SUPPORTED_OPTIONS=	snmp ssl \
		squid-backend-aufs squid-backend-null \
		squid-backend-ufs squid-carp squid-unlinkd \
		squid-ldap-helper squid-pam-helper

PKG_OPTIONS_LEGACY_OPTS=	aufs:squid-backend-aufs \
	coss:squid-backend-coss diskd:squid-backend-diskd \
	null:squid-backend-null ufs:squid-backend-ufs \
	linux-netfilter:squid-netfilter ipf-transparent:squid-ipf \
	pf-transparent:squid-pf unlinkd:squid-unlinkd \
	arp-acl:squid-arp-acl pam-helper:squid-pam-helper carp:squid-carp

PLIST_VARS+=	coss diskd snmp unlinkd
PLIST_VARS+=	ba_LDAP ba_MSNT ba_NCSA ba_PAM ba_YP ba_getpwnam
PLIST_VARS+=	da_ldap da_password
PLIST_VARS+=	na_SMB na_fakeauth
PLIST_VARS+=	eacl_ip_user eacl_ldap_group eacl_unix_group

#
# most of options are enabled by default except aufs.  aufs backend isn't
# tested well.
PKG_SUGGESTED_OPTIONS=	squid-carp snmp ssl squid-pam-helper squid-unlinkd

.include "../../mk/bsd.prefs.mk"

#
# Squid 3.0's COSS support is not stable now.
#
.if !empty(PKGNAME:Msquid-2.[0-9]*.[0-9]*)
PKG_SUPPORTED_OPTIONS+=	squid-backend-coss 
PKG_SUGGESTED_OPTIONS+=	squid-backend-coss
.endif

.if !empty(OPSYS:MLinux)
PKG_SUPPORTED_OPTIONS+=	squid-netfilter
.endif

# some release of NetBSD lacks <ipl.h> header of IP Filter 4.x
.if ${OPSYS} != "NetBSD" || ${OS_VERSION:M[01].*} || exists(/usr/include/netinet/ipl.h)
PKG_SUPPORTED_OPTIONS+=	squid-ipf
.endif

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD" || ${OPSYS} == "DragonFly"
PKG_SUPPORTED_OPTIONS+=	squid-pf
.endif

.if (${OPSYS} == "FreeBSD" || ${OPSYS} == "NetBSD") && \
	!empty(PKG_SUPPORTED_OPTIONS:Msquid-ipf)
PKG_SUGGESTED_OPTIONS+=	squid-ipf
.endif

.if ${OPSYS} == "OpenBSD"
PKG_SUGGESTED_OPTIONS+=	squid-pf
.endif

# Darwin dosen't support System V IPC support.
.if empty(OPSYS:MDarwin)
PKG_SUPPORTED_OPTIONS+=	squid-backend-diskd
PKG_SUGGESTED_OPTIONS+=	squid-backend-diskd
PLIST.diskd=		yes
.endif

# limited platform support squid-arp-acl
.if !empty(OPSYS:MFreeBSD) || !empty(OPSYS:MNetBSD) || !empty(OPSYS:MOpenBSD) || !empty(OPSYS:MLinux) || !empty(OPSYS:MSunOS)
PKG_SUPPORTED_OPTIONS+=	squid-arp-acl
.endif

.include "../../mk/bsd.options.mk"

SQUID_BACKENDS?=		ufs null
SQUID_BASIC_AUTH_HELPERS?=	getpwnam MSNT NCSA YP
SQUID_DIGEST_AUTH_HELPERS?=	password
SQUID_NTLM_AUTH_HELPERS?=	fakeauth SMB
SQUID_EXTERNAL_ACL_HELPERS?=	ip_user unix_group

#
# squid's code has preference as:
#	squid-ipf > squid-pf > squid-netfilter
# So, options.mk introduce preference as:
#	squid-netfilter > squid-pf > squid-ipf
#
.if !empty(PKG_OPTIONS:Msquid-netfilter)
CONFIGURE_ARGS+=	--enable-linux-netfilter
.elif !empty(PKG_OPTIONS:Msquid-pf)
CONFIGURE_ARGS+=	--enable-pf-transparent
.elif !empty(PKG_OPTIONS:Msquid-ipf)
CONFIGURE_ARGS+=	--enable-ipf-transparent
.endif

.if !empty(PKG_OPTIONS:Msquid-arp-acl)
CONFIGURE_ARGS+=	--enable-arp-acl
.endif

.if !empty(PKG_OPTIONS:Msquid-carp)
CONFIGURE_ARGS+=	--enable-carp
.endif

.if !empty(PKG_OPTIONS:Msquid-ldap-helper)
.include "../../databases/openldap-client/buildlink3.mk"
SQUID_BASIC_AUTH_HELPERS+=	LDAP
SQUID_DIGEST_AUTH_HELPERS+=	ldap
SQUID_EXTERNAL_ACL_HELPERS+=	ldap_group
.endif

.if !empty(PKG_OPTIONS:Msquid-pam-helper)
.  include "../../mk/pam.buildlink3.mk"
SQUID_BASIC_AUTH_HELPERS+=	PAM
.endif

.if !empty(PKG_OPTIONS:Msnmp)
CONFIGURE_ARGS+=	--enable-snmp
PLIST.snmp=		yes
.endif

.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--enable-ssl --with-openssl=${SSLBASE:Q}
.include "../../security/openssl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msquid-backend-aufs)
SQUID_BACKENDS+=	aufs
PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msquid-backend-coss)
.if empty(PKG_OPTIONS:Msquid-backend-aufs)
SQUID_BACKENDS+=	aufs
PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"
.endif
SQUID_BACKENDS+=	coss
PLIST.coss=		yes
.endif

.if !empty(PKG_OPTIONS:Msquid-backend-diskd)
SQUID_BACKENDS+=	diskd
PLIST.diskd=		yes
.endif

.if empty(PKG_OPTIONS:Msquid-unlinkd)
CONFIGURE_ARGS+=	--disable-unlinkd
.else
PLIST.unlinkd=		yes
.endif

.if !empty(SQUID_BASIC_AUTH_HELPERS)
CONFIGURE_ARGS+= --enable-basic-auth-helpers=${SQUID_BASIC_AUTH_HELPERS:Q}
.for i in ${SQUID_BASIC_AUTH_HELPERS}
PLIST.ba_${i}=		yes
.endfor
.endif

.if !empty(SQUID_DIGEST_AUTH_HELPERS)
CONFIGURE_ARGS+= --enable-digest-auth-helpers=${SQUID_DIGEST_AUTH_HELPERS:Q}
.for i in ${SQUID_DIGEST_AUTH_HELPERS}
PLIST.da_${i}=		yes
.endfor
.endif

.if !empty(SQUID_NTLM_AUTH_HELPERS)
CONFIGURE_ARGS+= --enable-ntlm-auth-helpers=${SQUID_NTLM_AUTH_HELPERS:Q}
.for i in ${SQUID_NTLM_AUTH_HELPERS}
PLIST.na_${i}=		yes
.endfor
.endif

.if !empty(SQUID_EXTERNAL_ACL_HELPERS)
CONFIGURE_ARGS+= --enable-external-acl-helpers=${SQUID_EXTERNAL_ACL_HELPERS:Q}
.for i in ${SQUID_EXTERNAL_ACL_HELPERS}
PLIST.eacl_${i}=	yes
.endfor
.endif
