# $NetBSD: Makefile,v 1.1.1.1 2001/02/02 18:24:13 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		ldap
CATEGORIES+=		databases

DEPENDS+=		openldap-1.2.*:../../databases/openldap

EVAL_PREFIX+=		LDAPDIR=openldap
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${LDAPDIR}

.include "../../mk/bsd.pkg.mk"
