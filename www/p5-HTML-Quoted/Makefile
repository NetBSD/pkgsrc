# $NetBSD: Makefile,v 1.3 2013/10/27 14:53:12 wen Exp $

DISTNAME=		HTML-Quoted-0.04
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/HTML-Quoted/
COMMENT=		Perl5 module to extract structure of quoted HTML mail message
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser

PERL5_PACKLIST=		auto/HTML/Quoted/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
