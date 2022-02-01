# $NetBSD: Makefile,v 1.63 2022/02/01 11:46:28 wiz Exp $

DISTNAME=	mod_perl-2.0.12
PKGNAME=	${APACHE_PKG_PREFIX}-${DISTNAME:S/mod_//}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_APACHE:=perl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://perl.apache.org/
COMMENT=	Module that embeds a Perl interpreter into Apache
LICENSE=	apache-2.0

CONFLICTS=	ap-perl-[0-9]* p5-Apache-Reload-[0-9]* p5-Apache-Test-[0-9]*

APACHE_MODULE=		yes
PERL5_PACKLIST=		auto/mod_perl2/.packlist

MAKE_PARAMS+=		MP_APXS=${APXS}
MAKE_PARAMS+=		MP_APR_CONFIG=${BUILDLINK_DIR}/bin/apr-config

INSTALLATION_DIRS=	${PREFIX}/share/doc/mod_perl

post-install:
	${CP} -R ${WRKSRC}/docs/* ${DESTDIR}${PREFIX}/share/doc/mod_perl

.include "../../lang/perl5/module.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
