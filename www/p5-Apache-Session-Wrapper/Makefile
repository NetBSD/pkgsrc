# $NetBSD: Makefile,v 1.33 2022/06/28 11:37:09 wiz Exp $

DISTNAME=		Apache-Session-Wrapper-0.34
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		8
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Apache-Session-Wrapper
COMMENT=		Perl5 module doing a wrapper around Apache::Session
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Class-Container-[0-9]*:../../devel/p5-Class-Container
DEPENDS+=		p5-Exception-Class-[0-9]*:../../devel/p5-Exception-Class
DEPENDS+=		p5-Apache-Session>=1.6:../../www/p5-Apache-Session

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Apache/Session/Wrapper/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
