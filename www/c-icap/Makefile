# $NetBSD: Makefile,v 1.24 2019/10/14 11:00:56 sborrill Exp $

DISTNAME=	c_icap-0.5.5
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=c-icap/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://c-icap.sourceforge.net/
COMMENT=	Implementation of an ICAP server
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-large-files

EGDIR=		${PREFIX}/share/c-icap
CONF_FILES=	${EGDIR}/c-icap.conf.default ${PKG_SYSCONFDIR}/c-icap.conf
CONF_FILES+=	${EGDIR}/c-icap.magic.default ${PKG_SYSCONFDIR}/c-icap.magic

BUILD_DEFS+=		VARBASE

SUBST_CLASSES+=		fix-path
SUBST_CLASSES+=		fix-ldap
SUBST_STAGE.fix-path=	pre-configure
SUBST_MESSAGE.fix-path=	Fixing paths.
SUBST_FILES.fix-path=	c-icap.conf.in
SUBST_SED.fix-path=	-e 's, @prefix@/var, ${VARBASE},g'
SUBST_SED.fix-path+=	-e 's, /var, ${VARBASE},g'
SUBST_STAGE.fix-ldap=	post-configure
SUBST_MESSAGE.fix-ldap=	Fixing LDAP.
SUBST_FILES.fix-ldap=	modules/Makefile
SUBST_SED.fix-ldap=	-e 's,-DLDAP_DEPRECATED,,g'

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
