# $NetBSD: Makefile,v 1.10 2022/06/28 11:37:45 wiz Exp $

DISTNAME=	URI-Query-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	www net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=URI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/URI-Query
COMMENT=	Perl5 module providing URI query string manipulation
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/URI/Query/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
