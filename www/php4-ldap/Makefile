# $NetBSD: Makefile,v 1.2 2001/02/17 17:22:33 wiz Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		ldap
CATEGORIES+=		databases

COMMENT=		PHP4 extension for LDAP databases

DEPENDS+=		openldap-1.2.*:../../databases/openldap

EVAL_PREFIX+=		LDAPDIR=openldap
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${LDAPDIR}

.include "../../mk/bsd.pkg.mk"
