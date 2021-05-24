# $NetBSD: Makefile,v 1.33 2021/05/24 19:55:19 wiz Exp $

DISTNAME=		Apache-Test-1.42
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=		adam@migus.org
HOMEPAGE=		https://metacpan.org/release/Apache-Test
COMMENT=		Wrapper for Test.pm to test an Apache server
LICENSE=		apache-2.0

CONFLICTS+=		ap2-perl-[0-9]*

DEPENDS+=		apache-[0-9]*:../../www/apache24

USE_LANGUAGES=		# none
PERL5_PACKLIST=		auto/Apache/Test/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
