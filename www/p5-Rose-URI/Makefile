# $NetBSD: Makefile,v 1.18 2019/08/11 13:24:59 wiz Exp $

DISTNAME=	Rose-URI-1.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/J/JS/JSIRACUSA/

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
