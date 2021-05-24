# $NetBSD: Makefile,v 1.19 2021/05/24 19:55:53 wiz Exp $

DISTNAME=	URI-FromHash-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	www net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=URI/}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/URI-FromHash
COMMENT=	Build a URI from a set of named parameters
LICENSE=	artistic-2.0

DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-Params-Validate-[0-9]*:../../devel/p5-Params-Validate

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/URI/FromHash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
