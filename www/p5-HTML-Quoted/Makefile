# $NetBSD: Makefile,v 1.15 2023/10/22 08:04:31 wen Exp $

DISTNAME=		HTML-Quoted-0.05
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/HTML-Quoted
COMMENT=		Perl5 module to extract structure of quoted HTML mail message
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser

PERL5_PACKLIST=		auto/HTML/Quoted/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
