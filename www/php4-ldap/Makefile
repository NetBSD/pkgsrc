# $NetBSD: Makefile,v 1.4 2001/05/14 14:12:32 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		ldap
CATEGORIES+=		databases
PHP_PKG_VERS=		# empty

COMMENT=		PHP4 extension for LDAP databases

DEPENDS+=		openldap-1.2.*:../../databases/openldap

EVAL_PREFIX+=		LDAPDIR=openldap
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${LDAPDIR}

.include "../../mk/bsd.pkg.mk"
