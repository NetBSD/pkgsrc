# $NetBSD: Makefile,v 1.85 2024/09/08 08:30:21 wiz Exp $

DISTNAME=	URI-5.29
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=URI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/URI
COMMENT=	Perl5 Uniform Resource Identifiers class (URI, RFC 2396)
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-MIME-Base32-[0-9]*:../../converters/p5-MIME-Base32
TEST_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
TEST_DEPENDS+=	p5-Test-Needs-[0-9]*:../../devel/p5-Test-Needs
TEST_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/URI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
