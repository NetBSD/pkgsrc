# $NetBSD: Makefile,v 1.24 2022/06/28 11:37:21 wiz Exp $

DISTNAME=		HTML-Element-Extended-1.18
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		13
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/HTML-Element-Extended
COMMENT=		Perl5 modules for managing HTML::Element based objects
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-HTML-Tree>=0:../../www/p5-HTML-Tree

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/HTML-Element-Extended/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
