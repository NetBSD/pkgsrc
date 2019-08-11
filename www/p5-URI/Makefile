# $NetBSD: Makefile,v 1.72 2019/08/11 13:25:02 wiz Exp $

DISTNAME=	URI-1.76
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=URI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/URI
COMMENT=	Perl5 Uniform Resource Identifiers class (URI, RFC 2396)
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Needs-[0-9]*:../../devel/p5-Test-Needs

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/URI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
