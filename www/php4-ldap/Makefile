# $NetBSD: Makefile,v 1.3 2001/03/01 18:18:16 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		ldap
CATEGORIES+=		databases
PHP_PKG_VERS=		nb1

COMMENT=		PHP4 extension for LDAP databases

DEPENDS+=		openldap-1.2.*:../../databases/openldap

EVAL_PREFIX+=		LDAPDIR=openldap
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${LDAPDIR}

.include "../../mk/bsd.pkg.mk"
