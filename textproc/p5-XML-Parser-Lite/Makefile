# $NetBSD: Makefile,v 1.10 2020/08/31 18:12:11 wiz Exp $

DISTNAME=	XML-Parser-Lite-0.722
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
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
