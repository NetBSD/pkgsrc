# $NetBSD: Makefile,v 1.16 2026/07/16 19:05:26 wiz Exp $

DISTNAME=	XML-Parser-Lite-0.722
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-ParserLite
COMMENT=	Lightweight regexp-based XML parser
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires

PERL5_PACKLIST=		auto/XML/Parser/Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
