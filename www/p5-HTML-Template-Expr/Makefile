# $NetBSD: Makefile,v 1.6 2015/06/12 10:52:01 wiz Exp $

DISTNAME=		HTML-Template-Expr-0.07
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/} \
			${MASTER_SITE_SOURCEFORGE:=html-template/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/HTML-Template-Expr/
COMMENT=		Perl5 module to create HTML templates with simple expressions
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Parse-RecDescent-[0-9]*:../../devel/p5-Parse-RecDescent

PERL5_PACKLIST=		auto/HTML/Template/Expr/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
