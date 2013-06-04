# $NetBSD: Makefile,v 1.44 2013/06/04 13:48:40 adam Exp $

DISTNAME=	mod_perl-2.0.8
PKGNAME=	${APACHE_PKG_PREFIX}-${DISTNAME:S/mod_//}
CATEGORIES=	www perl5
MASTER_SITES=	http://apache.org/dist/perl/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://perl.apache.org/
COMMENT=	Module that embeds a Perl interpreter into Apache
LICENSE=	apache-2.0

CONFLICTS=	ap-perl-[0-9]* p5-Apache-Reload-[0-9]* p5-Apache-Test-[0-9]*

PKG_APACHE_ACCEPTED=	apache2 apache22

APACHE_MODULE=		yes
PERL5_PACKLIST=		auto/mod_perl2/.packlist

MAKE_PARAMS+=		MP_APXS=${APXS}

INSTALLATION_DIRS=	${PREFIX}/share/doc/mod_perl

post-install:
	${CP} -R ${WRKSRC}/docs/* ${DESTDIR}${PREFIX}/share/doc/mod_perl

.include "../../lang/perl5/module.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
