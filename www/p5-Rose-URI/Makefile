# $NetBSD: Makefile,v 1.22 2022/06/28 11:37:41 wiz Exp $

DISTNAME=	Rose-URI-1.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JS/JSIRACUSA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Rose-URI
COMMENT=	URI class for easy and efficient manipulation of URI components
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Rose-Object>=0.15:../../devel/p5-Rose-Object
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Rose/URI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
