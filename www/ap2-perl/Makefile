# $NetBSD: Makefile,v 1.56 2018/08/22 09:42:52 wiz Exp $

DISTNAME=	mod_perl-2.0.10
PKGNAME=	${APACHE_PKG_PREFIX}-${DISTNAME:S/mod_//}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_APACHE:=perl/}
PKGREVISION=	2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://perl.apache.org/
COMMENT=	Module that embeds a Perl interpreter into Apache
LICENSE=	apache-2.0

CONFLICTS=	ap-perl-[0-9]* p5-Apache-Reload-[0-9]* p5-Apache-Test-[0-9]*

APACHE_MODULE=		yes
PERL5_PACKLIST=		auto/mod_perl2/.packlist

MAKE_PARAMS+=		MP_APXS=${APXS}
MAKE_PARAMS+=		MP_APR_CONFIG=${BUILDLINK_DIR}/bin/apr-config

.include "../../mk/apache.mk"

.if !empty(PKG_APACHE:Mapache24)
SUBST_CLASSES+=		ap24
SUBST_STAGE.ap24=	pre-configure
SUBST_MESSAGE.ap24=	Adding Apache 2.4.x compatibility.
SUBST_FILES.ap24=	xs/maps/apache2_structures.map
SUBST_FILES.ap24+=	xs/tables/current/Apache2/StructureTable.pm
SUBST_SED.ap24=		-e "s,remote_addr,client_addr,g"
SUBST_SED.ap24+=	-e "s,remote_ip,client_ip,g"
SUBST_SED.ap24+=	-e "s,'loglevel','log.level',g"
.endif

INSTALLATION_DIRS=	${PREFIX}/share/doc/mod_perl

post-install:
	${CP} -R ${WRKSRC}/docs/* ${DESTDIR}${PREFIX}/share/doc/mod_perl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
