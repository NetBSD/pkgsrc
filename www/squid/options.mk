# $NetBSD: options.mk,v 1.3 2005/06/07 14:19:10 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.squid
PKG_SUPPORTED_OPTIONS=	icmp pam-helper snmp ssl aufs
#
# most of options are enabled by default except aufs.  aufs backend isn't
# tested well.
PKG_SUGGESTED_OPTIONS=	icmp pam-helper snmp ssl

.if !empty(OPSYS:MLinux)
PKG_SUPPORTED_OPTIONS+=	linux-netfilter
.endif

# some release of NetBSD lacks <ipl.h> header of IP Filter 4.x
.if ${OPSYS} != "NetBSD" || ${OS_VERSION:M[01].*} || exists(/usr/include/netinet/ipl.h)
PKG_SUPPORTED_OPTIONS+=	ipf-transparent
.endif

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
PKG_SUPPORTED_OPTIONS+=	pf-transparent
.endif

.if (${OPSYS} == "FreeBSD" || ${OPSYS} == "NetBSD") && \
	!empty(PKG_SUPPORTED_OPTIONS:Mipf-transparent)
PKG_SUGGESTED_OPTIONS+=	ipf-transparent
.endif

.if ${OPSYS} == "OpenBSD"
PKG_SUGGESTED_OPTIONS+=	pf-transparent
.endif

# Darwin dosen't support System V IPC support.
.if empty(OPSYS:MDarwin)
PKG_SUPPORTED_OPTIONS+=	diskd
PKG_SUGGESTED_OPTIONS+=	diskd
.endif

# limited platform support arp-acl
.if !empty(OPSYS:MFreeBSD) || !empty(OPSYS:MLinux) || !empty(OPSYS:MSunOS)
PKG_SUPPORTED_OPTIONS+=	arp-acl
.endif

.include "../../mk/bsd.options.mk"

SQUID_BACKEND?=			ufs null
SQUID_BASIC_AUTH_HELPERS?=	getpwnam MSNT NCSA YP winbind
SQUID_DIGEST_AUTH_HELPERS?=	password
SQUID_NTLM_AUTH_HELPERS?=	fakeauth SMB
SQUID_EXTERNAL_ACL_HELPERS?=	ip_user unix_group

#
# squid's code has preference as:
#	ipf-transparent > pf-transparent > linux-netfilter
# So, options.mk introduce preference as:
#	linux-netfilter > pf-transparnet > ipf-transparent
#
.if !empty(PKG_OPTIONS:Mlinux-netfilter)
CONFIGURE_ARGS+=	--enable-linux-netfilter
.elif !empty(PKG_OPTIONS:Mpf-transparent)
CONFIGURE_ARGS+=	--enable-pf-transparent
.elif !empty(PKG_OPTIONS:Mipf-transparent)
CONFIGURE_ARGS+=	--enable-ipf-transparent
.endif

.if !empty(PKG_OPTIONS:Marp-acl)
CONFIGURE_ARGS+=	arp-acl
.endif

.if !empty(PKG_OPTIONS:Micmp)
CONFIGURE_ARGS+=	--enable-icmp
.endif

.if !empty(PKG_OPTIONS:Mpam-helper)
.  include "../../mk/pam.buildlink3.mk"
SQUID_BASIC_AUTH_HELPERS+=	PAM
.endif

.if !empty(PKG_OPTIONS:Msnmp)
CONFIGURE_ARGS+=	--enable-snmp
.endif

.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--enable-ssl --with-openssl=${SSLBASE}
.include "../../security/openssl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdiskd)
SQUID_BACKEND+=		diskd
.endif

.if !empty(SQUID_BASIC_AUTH_HELPERS)
CONFIGURE_ARGS+= --enable-basic-auth-helpers=${SQUID_BASIC_AUTH_HELPERS:Q}
.endif

.if !empty(SQUID_DIGEST_AUTH_HELPERS)
CONFIGURE_ARGS+= --enable-digest-auth-helpers=${SQUID_DIGEST_AUTH_HELPERS:Q}
.endif

.if !empty(SQUID_NTLM_AUTH_HELPERS)
CONFIGURE_ARGS+= --enable-ntlm-auth-helpers=${SQUID_NTLM_AUTH_HELPERS:Q}
.endif

.if !empty(SQUID_EXTERNAL_ACL_HELPERS)
CONFIGURE_ARGS+= --enable-external-acl-helpers=${SQUID_EXTERNAL_ACL_HELPERS:Q}
.endif
