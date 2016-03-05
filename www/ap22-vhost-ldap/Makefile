# $NetBSD: Makefile,v 1.9 2016/03/05 11:29:35 jperkin Exp $

MVL_VERSION=		1.2.0
DISTNAME=		mod-vhost-ldap_${MVL_VERSION}.orig
PKGNAME=		${APACHE_PKG_PREFIX}-vhost-ldap-${MVL_VERSION}
PKGREVISION=		7
CATEGORIES=		www databases
MASTER_SITES=		${MASTER_SITE_DEBIAN:=pool/main/m/mod-vhost-ldap/}

MAINTAINER=		imil@gcu.info
HOMEPAGE=		http://packages.qa.debian.org/m/mod-vhost-ldap.html
COMMENT=		Apache 2.2 module LDAP Virtual Hosts support

WRKSRC=			${WRKDIR}/${DISTNAME:S/_/-/:S/.orig//}
NO_CONFIGURE=		yes

APACHE_MODULE_NAME=	mod_vhost_ldap

PKG_APACHE_ACCEPTED=	apache22

AUTO_MKDIRS=		yes

do-build:
	cd ${WRKSRC} &&								\
	${APXS} -c -n ${APACHE_MODULE_NAME}					\
		-I${BUILDLINK_PREFIX.openldap-client}/include			\
		-L${BUILDLINK_PREFIX.openldap-client}/lib			\
		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openldap-client}/lib	\
		-DMOD_VHOST_LDAP_VERSION=\\\"mod_vhost_ldap/${MVL_VERSION}\\\"	\
		-lldap_r mod_vhost_ldap.c

do-install:
	cd ${WRKSRC} &&								\
	${APXS} -i -n ${APACHE_MODULE_NAME} ${APACHE_MODULE_NAME}.la
	${INSTALL_DATA} ${WRKSRC}/vhost_ldap.conf 				\
		${DESTDIR}${PREFIX}/share/examples/mod_vhost_ldap
	${INSTALL_DATA} ${WRKSRC}/mod_vhost_ldap.schema 			\
		${DESTDIR}${PREFIX}/share/examples/mod_vhost_ldap

.include "../../devel/apr-util/buildlink3.mk"
.if empty(PKG_BUILD_OPTIONS.apr-util:Mldap)
PKG_FAIL_REASON+=       "PKG_OPTIONS.apr-util must contain the ldap parameter"
.endif

.include "../../mk/apache.mk"
.include "../../databases/openldap-client/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
